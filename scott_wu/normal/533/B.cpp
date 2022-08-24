#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, root;
vector <int> child[MAXN];
int eff[MAXN];

ll dp[MAXN][2];

void solve (int cloc)
{
    for (int i = 0; i < child[cloc].size(); i++)
    {
        solve (child[cloc][i]);
    }
    
    ll b[2];
    b[0] = 0, b[1] = -1e12;
    
    for (int i = 0; i < child[cloc].size(); i++)
    {
        int neigh = child[cloc][i];
        
        ll c[2];
        c[0] = -1e12, c[1] = -1e12;
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                c[(j+k)%2] = max (c[(j+k)%2], b[j] + dp[neigh][k]);
            }
        }
        
        //if (cloc == 0)
        //    cout << c[0] << " " << c[1] << "\n";
        
        b[0] = c[0];
        b[1] = c[1];
    }
    
    // either use cloc or don't
    dp[cloc][1] = max (b[1], eff[cloc] + b[0]);
    dp[cloc][0] = b[0];
    
    //cout << cloc << " " << dp[cloc][0] << " " << dp[cloc][1] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == -1)
        {
            root = i;
            eff[i] = b;
            continue;
        }
        
        a--;
        child[a].push_back(i);
        eff[i] = b;
    }
    
    solve (root);
    cout << max (dp[root][0], dp[root][1]) << "\n";
    return 0;
}