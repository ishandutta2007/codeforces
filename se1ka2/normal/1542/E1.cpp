#include <iostream>
using namespace std;
typedef long long ll;

ll dp[52][2502];
ll s[52][2502];

ll rec(int n, ll m){
    if(n == 0) return 0;
    ll res = rec(n - 1, m) * n;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            for(int k = j - i; k <= n * (n - 1) / 2 + 1; k++){
                res = (res + dp[n - 1][k] * s[n - 1][k - (j - i)]) % m;
            }
        }
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        ll d[2502]{0};
        for(int j = 1; j <= i; j++){
            for(int k = j - 1; k <= n * n; k++) d[k] = (d[k] + dp[i - 1][k - (j - 1)]) % m;
        }
        swap(dp[i], d);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n * n + 1; j++) s[i][j] = (s[i][j - 1] + dp[i][j - 1]) % m;
    }
    cout << rec(n, m) << endl;
}