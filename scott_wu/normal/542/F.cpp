#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 1100;

int N, T;
vector <int> qposs[MAXN];
int dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> T;
    for (int i = 0; i < N; i++)
    {
        int t, q;
        cin >> t >> q;
        qposs[t].push_back (q);
    }
    
    for (int i = 0; i < MAXN; i++)
        dp[i] = 0;
    
    for (int i = 0; i <= T; i++)
    {
        for (int j = 1; j <= N; j++)
            if (j * 2 > N + 3)
                dp[j] = 0;
            else
                dp[j] = max (dp[2*j-1], dp[2*j]);
        
        for (int j = 0; j < qposs[i].size(); j++)
        {
            int cval = qposs[i][j];
            for (int k = N; k > 0; k--)
                dp[k] = max (dp[k], dp[k-1] + cval);
        }
    }
    
    cout << max (0, dp[1]) << "\n";
    return 0;
}