#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const int MAXM = 300100;

int N, M;
int deg[MAXN];
pair <int, int> elist[MAXM];
bool used[MAXM];
vector <pair <int, int> > res;

bool odeg[MAXN]; // true if odd degree
vector <pair <int, int> > edge[MAXN];
bool seen[MAXN];

void solve (int cloc, int ledge)
{
    seen[cloc] = true;
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        int neigh = edge[cloc][i].first, eval = edge[cloc][i].second;
        if (eval == ledge) continue;
        
        if (seen[neigh])
        {
            if (!used[eval])
            {
                used[eval] = true;
                res.push_back (make_pair (cloc, neigh));
                odeg[cloc] = !odeg[cloc];
            }
        }
        else
            solve (neigh, eval);
    }
    
    //cout << cloc << " " << ledge << " " << (odeg[cloc] ? 1 : 0) << endl;
    
    if (ledge != -1)
    {
        int x = elist[ledge].first, y = elist[ledge].second;
        if (y == cloc)
            swap (x, y);
        
        if (odeg[cloc])
        {
            odeg[cloc] = false;
            used[ledge] = true;
            res.push_back (make_pair (x, y));
        }
        else
        {
            used[ledge] = true;
            odeg[y] = !odeg[y];
            res.push_back (make_pair (y, x));
        }
    }
    else
    {
        if (odeg[cloc])
        {
            res.push_back (make_pair (cloc, cloc));
            odeg[cloc] = false;
        }
    }
}

bool cseen[MAXN];
int cdeg[MAXN];
vector <pair <int, int> > cvec;
vector <int> estart[MAXN];

void run (int cloc)
{
    if (cseen[cloc]) return;
    cseen[cloc] = true;
    if (cdeg[cloc] % 2 == 1)
    {
        int ind = (int) cvec.size() - 1;
        if (cvec[ind].first == -1)
            cvec[ind].first = cloc;
        else if (cvec[ind].second == -1)
            cvec[ind].second = cloc;
    }
    
    for (int i = 0; i < estart[cloc].size(); i++)
        run (estart[cloc][i]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    for (int i = 0; i < MAXN; i++)
    {
        cseen[i] = false;
        deg[i] = cdeg[i] = 0;
    }
    
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        deg[x]++, deg[y]++;
        cdeg[x]++, cdeg[y]++;
        
        elist[i] = make_pair (x, y);
        estart[x].push_back (y);
        estart[y].push_back (x);
    }
    
    for (int i = 0; i < N; i++)
    {
        if (!cseen[i])
        {
            cvec.push_back(make_pair (-1, -1));
            run (i);
            if (cvec[cvec.size() - 1].second == -1)
                cvec.pop_back();
        }
    }
    
    for (int i = 0; i < cvec.size(); i++)
    {
        int x = cvec[i].second, y = cvec[(i + 1) % cvec.size()].first;
        deg[x]++, deg[y]++;
        elist[M++] = make_pair (x, y);
    }
    
    int clast = -1;
    for (int i = 0; i < N; i++)
    {
        if (deg[i] % 2 == 1)
        {
            if (clast == -1)
                clast = i;
            else
            {
                elist[M++] = make_pair (clast, i);
                clast = -1;
            }
        }
    }
    
    for (int i = 0; i < M; i++)
    {
        used[i] = false;
        int x = elist[i].first, y = elist[i].second;
        edge[x].push_back (make_pair (y, i));
        edge[y].push_back (make_pair (x, i));
    }
    
    for (int i = 0; i < N; i++)
        odeg[i] = seen[i] = false;
    
    for (int i = 0; i < N; i++)
    {
        if (!seen[i])
            solve (i, -1);
    }
    
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i].first + 1 << " " << res[i].second + 1 << "\n";
    }
    return 0;
}