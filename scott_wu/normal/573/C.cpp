#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
vector <int> edge[MAXN];
int mdeg[MAXN], odeg[MAXN]; // max degree with and without root

void flood (int cloc, int last)
{
    mdeg[cloc] = edge[cloc].size();
    odeg[cloc] = 0;
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        if (edge[cloc][i] == last) continue;
        
        int neigh = edge[cloc][i];
        flood (neigh, cloc);
        mdeg[cloc] = max (mdeg[cloc], mdeg[neigh]);
        odeg[cloc] = max (odeg[cloc], mdeg[neigh]);
    }
}

bool bad;

void flood2 (int cloc, int last)
{
    int ccnt = 0;
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        if (edge[cloc][i] == last) continue;
        
        int neigh = edge[cloc][i];
        if (mdeg[neigh] >= 3)
        {
            if (mdeg[neigh] == 3 && odeg[neigh] < 3)
                continue;
            ccnt++;
            flood2 (neigh, cloc);
        }
    }
    
    if (last == -1 && ccnt > 2)
        bad = true;
    if (last != -1 && ccnt > 1)
        bad = true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back (b);
        edge[b].push_back (a);
    }
    
    int cloc = 0;
    for (int i = 1; i < N; i++)
        if (edge[i].size() > edge[cloc].size())
            cloc = i;
    
    if (edge[cloc].size() <= 2)
    {
        cout << "Yes\n";
        return 0;
    }
    
    flood (cloc, -1);
    
    if (edge[cloc].size() == 3)
    {
        int ccnt = 0, val = -1;
        for (int i = 0; i < edge[cloc].size(); i++)
        {
            int neigh = edge[cloc][i];
            if (mdeg[neigh] >= 3)
            {
                ccnt++;
                val = neigh;
            }
        }
        
        if (ccnt == 1)
        {
            cloc = val;
            flood (val, -1);
        }
    }
    
    bad = false;
    flood2 (cloc, -1);
    
    if (bad) cout << "No\n";
    else cout << "Yes\n";
    //system ("Pause");
    return 0;
}