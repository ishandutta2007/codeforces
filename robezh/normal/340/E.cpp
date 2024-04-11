#include <bits/stdc++.h>
using namespace std;

const int N = 2005, mod = (int)1e9 + 7;
typedef long long ll;

int n;
int num[N];
ll fac[N];
ll dp[N][N];
bool used_loc[N], used_num[N];

ll get(int k, int m) {
    if(dp[k][m] != -1) return dp[k][m];
    dp[k][m] = 0;
    if(k == 0) return dp[k][m] = fac[m];
    dp[k][m] += m * get(k-1, m);
    if(k >= 2) dp[k][m] += (k - 1) * get(k-2, m+1);
    dp[k][m] %= mod;
    return dp[k][m];
}

int main() {
    memset(dp, -1, sizeof(dp));
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = fac[i-1] * i % mod;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
        if(num[i] != -1) {
            used_loc[i] = true;
            used_num[num[i]] = true;
        }
    }
    int inter = 0, non = 0;
    for(int i = 1; i <= n; i++) {
        if(!used_loc[i]) {
            inter += !used_num[i];
            non += used_num[i];
        }
    }
//    cout << inter << " " << non << endl;
    cout << get(inter, non) << endl;

}