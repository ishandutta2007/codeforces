#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

bool b[1002][1002];
ll dp[1002][1002];

ll dfs(int i, int k, int n){
    if(k == 0) return 0;
    if(i == n) return 1;
    if(b[i][k]) return dp[i][k];
    b[i][k] = true;
    return dp[i][k] = (dfs(i + 1, k, n) + dfs(n - i, k - 1, n)) % MOD;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= k; j++) b[i][j] = false;
        }
        cout << dfs(0, k, n) << endl;
    }
}