#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <cstring>
#include <cassert>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N;
pair <int, int> pp[MAXN];

int M1, M2;
vector <pair <int, pair <int, int> > > xray;
vector <pair <int, pair <int, int> > > yray;

inline bool cmp (pair <int, int> left, pair <int, int> right)
{
    if (left.second != right.second) return left.second < right.second;
    return left.first < right.first;
}

bool vuse[MAXN];
int vmatch[MAXN];
bool vedge[MAXN][MAXN];
vector <pair <int, int> > gg;
bool found[2][MAXN];

bool dfs(int cur) {
    if (vuse[cur]) return false;
    vuse[cur] = true;
    for (int i = 0; i < M2; i++) {
        if (vedge[cur][i]) {
            int nxt = vmatch[i];
            if (nxt == -1) {
                vmatch[i] = cur;
                return true;
            } else {
                vmatch[i] = cur;
                if (dfs(nxt)) {
                    return true;
                }
                vmatch[i] = nxt;
            }
        }
    }
    return false;
}

void match()
{
    memset(vmatch, -1, sizeof(vmatch));
    for (int i = 0; i < M1; i++)
    {
        memset(vuse, 0, sizeof(vuse));
        dfs(i);
    }
    for (int i = 0; i < M2; i++)
    {
        if (vmatch[i] == -1) continue;
        gg.push_back(make_pair(i, vmatch[i]));
    }
}

void flood (int ctype, int cloc)
{
    if (found[ctype][cloc]) return;
    found[ctype][cloc] = true;

    if (ctype == 1)
    {
        if (vmatch[cloc] != -1) flood (0, vmatch[cloc]);
    }
    else
    {
        for (int i = 0; i < M2; i++)
            if (vmatch[i] != cloc && vedge[cloc][i])
                flood (1, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> pp[i].first >> pp[i].second;
    sort (pp, pp + N);
    for (int i = 0; i < N - 1; i++)
    {
        if (pp[i].first == pp[i+1].first)
            xray.push_back(make_pair(pp[i].first, make_pair (pp[i].second, pp[i+1].second)));
    }
    sort (pp, pp + N, cmp);
    for (int i = 0; i < N - 1; i++)
    {
        if (pp[i].second == pp[i+1].second)
            yray.push_back(make_pair(pp[i].second, make_pair (pp[i].first, pp[i+1].first)));
    }

    M1 = xray.size();
    M2 = yray.size();
    for (int i = 0; i < M1; i++)
        for (int j = 0; j < M2; j++)
        {
            if (xray[i].first > yray[j].second.first && xray[i].first < yray[j].second.second)
                if (yray[j].first > xray[i].second.first && yray[j].first < xray[i].second.second)
                    vedge[i][j] = true;
        }

    match();
    //cout << gg.size() << " matches\n";

    for (int i = 0; i < M1; i++)
    {
        bool has = false;
        for (int j = 0; j < M2; j++)
            if (vmatch[j] == i) has = true;
        if (!has)
            flood (0, i);
    }

    for (int i = 0; i < M1; i++)
        found[0][i] = !found[0][i];

    vector <pair <int, pair <int, int> > > horiz, vert;
    sort (pp, pp + N);
    int cloc = 0;
    while (cloc < N)
    {
        int nloc = cloc + 1;
        while (nloc < N && pp[nloc].first == pp[cloc].first)
        {
            bool bad = false;
            for (int i = 0; i < M1; i++)
                if (found[0][i] && xray[i].first == pp[nloc].first && xray[i].second.second == pp[nloc].second)
                {
                    bad = true;
                    break;
                }
            if (bad) break;
            nloc++;
        }
        horiz.push_back(make_pair(pp[cloc].first, make_pair (pp[cloc].second, pp[nloc-1].second)));
        cloc = nloc;
    }
    sort (pp, pp + N, cmp);
    cloc = 0;
    while (cloc < N)
    {
        int nloc = cloc + 1;
        while (nloc < N && pp[nloc].second == pp[cloc].second)
        {
            bool bad = false;
            for (int i = 0; i < M2; i++)
                if (found[1][i] && yray[i].first == pp[nloc].second && yray[i].second.second == pp[nloc].first)
                {
                    bad = true;
                    break;
                }
            if (bad) break;
            nloc++;
        }
        vert.push_back(make_pair(pp[cloc].second, make_pair (pp[cloc].first, pp[nloc-1].first)));
        cloc = nloc;
    }

    cout << vert.size() << "\n";
    for (int i = 0; i < vert.size(); i++)
    {
        auto v = vert[i];
        cout << v.second.first << " " << v.first << " " << v.second.second << " " << v.first << "\n";
    }
    cout << horiz.size() << "\n";
    for (int i = 0; i < horiz.size(); i++)
    {
        cout << horiz[i].first << " " << horiz[i].second.first << " " << horiz[i].first << " " << horiz[i].second.second << "\n";
    }


    /*for (int i = 0; i < M1; i++)
    {
        if (found[0][i])
        {
            cout << 0 << " " << i << "\n";
        }
    }
    for (int i = 0; i < M2; i++)
        if (found[1][i])
        {
            cout << 1 << " " << i << "\n";
        }*/
}