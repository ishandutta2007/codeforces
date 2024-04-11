#include <iostream>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;
const int MAXT = 25;

int N;
int parent[MAXN];
vector <int> child[MAXN];
int ttime[MAXN][MAXT];

void solve (int cloc)
{
    for (int i = 0; i < child[cloc].size(); i++)
        solve (child[cloc][i]);
    
    ttime[cloc][0] = ttime[cloc][1] = cloc;
    for (int i = 0; i < child[cloc].size(); i++)
        for (int j = 0; j < MAXT; j++)
            ttime[cloc][j] = min (ttime[cloc][j], ttime[child[cloc][i]][j]);
    
    if (cloc == 0) return;
    
    for (int i = 1; i < MAXT; i++)
    {
        int lo = 1e9, slo = 1e9;
        for (int j = 0; j < child[cloc].size(); j++)
        {
            int neigh = child[cloc][j];
            if (ttime[neigh][i-1] < slo)
                slo = ttime[neigh][i-1];
            
            if (lo > slo)
                swap (lo, slo);
        }
        
        ttime[cloc][i] = min (ttime[cloc][i], slo);
    }
    
    /*cout << cloc << "\n";
    for (int i = 0; i < 3; i++)
        cout << ttime[cloc][i] << " ";
    cout << "\n";*/
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXT; j++)
            ttime[i][j] = 1e9;
    
    cin >> N;
    N++;
    for (int i = 1; i < N; i++)
    {
        cin >> parent[i];
        parent[i]--;
        child[parent[i]].push_back (i);
    }
    
    solve (0);
    
    int ctime = 0;
    for (int i = 1; i < N; i++)
    {
        while (ttime[0][ctime+1] <= i)
            ctime++;
        
        if (i > 1) cout << " ";
        cout << ctime;
    }
    cout << endl;
    //system ("Pause");
    return 0;
}