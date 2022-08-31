#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, M, D;
vector <int> edge[MAXN];
bool bad[MAXN];
int mdist[MAXN];

int dup[MAXN];

void solve (int cloc, int clast)
{
    mdist[cloc] = -1e9;
    if (bad[cloc])
        mdist[cloc] = 0;
    
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        int neigh = edge[cloc][i];
        
        if (neigh != clast)
        {
            solve (neigh, cloc);
            mdist[cloc] = max (mdist[cloc], mdist[neigh] + 1);
        }
    }
}


void solve2 (int cloc, int clast)
{
    if (dup[cloc] < 0 && bad[cloc]) dup[cloc] = 0;
    int hi = dup[cloc] - 1, hi2 = -1e9;
    
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        int neigh = edge[cloc][i];
        
        if (neigh != clast)
        {
            if (mdist[neigh] > hi2)
                hi2 = mdist[neigh];
            if (hi2 > hi)
                swap (hi, hi2);
            
            mdist[cloc] = max (mdist[cloc], mdist[neigh] + 1);
        }
    }
    
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        int neigh = edge[cloc][i];
        if (neigh != clast)
        {
            if (mdist[neigh] == hi)
                dup[neigh] = hi2 + 2;
            else
                dup[neigh] = hi + 2;
        }
    }
    
    for (int i = 0; i < edge[cloc].size(); i++)
    {
        int neigh = edge[cloc][i];
        if (neigh != clast)
        {
            solve2 (neigh, cloc);
        }
    }
}

int main()
{
    for (int i = 0; i < MAXN; i++)
        bad[i] = false;
    
    cin >> N >> M >> D;
    
    for (int i = 0; i < M; i++)
    {
        int x; cin >> x;
        bad[x-1] = true;
    }
    
    for (int i = 0; i < N - 1; i++)
    {
        int left, right;
        cin >> left >> right;
        left--, right--;
        
        edge[left].push_back (right);
        edge[right].push_back (left);
    }
    
    solve (0, -1);
    
    dup[0] = -1e9;
    solve2 (0, -1);
    
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        //cout << dup[i] << " " << mdist[i] << "\n";
        if (dup[i] <= D && mdist[i] <= D)
        {
            //cout << i << "\n";
            res++;
        }
    }
    cout << res << "\n";
    //system ("Pause");
    return 0;
}