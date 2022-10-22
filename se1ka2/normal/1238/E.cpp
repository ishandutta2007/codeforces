#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const int INF = 1000000000;

ll d[20][20];
ll b[1100000];
ll dp[1100000];
ll t[20][1100000];

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 1; i < (1 << m); i++){
        for(int j = 0; j < m; j++) if((i >> j) & 1){
            b[i] = b[i ^ (1 << j)] + 1;
            break;
        }
    }
    for(int i = 1; i < n; i++){
        d[s[i - 1] - 'a'][s[i] - 'a']++;
        d[s[i] - 'a'][s[i - 1] - 'a']++;
    }
    for(int j = 0; j < m; j++){
        for(int i = 0; i < (1 << m); i++){
            if((i >> j) & 1) continue;
            for(int k = 0; k < m; k++) if((i >> k) & 1){
                t[j][i] = t[j][i ^ (1 << k)] + d[j][k];
                break;
            }
        }
    }
    fill(dp, dp + (1 << m), INF);
    dp[0] = 0;
    for(int i = 1; i < (1 << m); i++){
        for(int j = 0; j < m; j++){
            if(!((i >> j) & 1)) continue;
            int k = (i ^ (1 << j));
            ll res = dp[k];
            res += b[i] * t[j][k];
            res -= b[i] * t[j][(~i) & ((1 << m) - 1)];
            dp[i] = min(dp[i], res);
        }
    }
    cout << dp[(1 << m) - 1] << endl;
}