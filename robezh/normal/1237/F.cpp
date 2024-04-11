#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5000;
const int mod = 998244353;

int h, w, n;
//int cov_r[N], cov_c[N];

ll fac[N], facinv[N];
ll inv[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
    if(n < 0 || k < 0 || n - k < 0) return 0;
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

void init_fac() {
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;
}

vector<int> calc(vector<int> cov) {
    int alen = 0, len = cov.size();
    for(int i = 0; i < cov.size(); i++) alen += !cov[i];
    vector<vector<int> > dp(alen + 1, vector<int>(alen + 1, 0));
    dp[0][0] = 1;
    int r = 0;
    int cur = 0;
    for(int i = 0; i < len; ) {
        if(cov[i]) {
            i++;
            continue;
        }
        r = i;
        while(r < len && !cov[r]) r++;
        for(int j = i; j < r; j++) {
            cur++;
            for(int k = 0; k <= alen; k++) {
                dp[cur][k] = dp[cur-1][k];
                if(j != i && k >= 1) dp[cur][k] = (dp[cur][k] + dp[cur-2][k-1]) % mod;
            }
        }
        i = r;
    }
    return dp[alen];
}

int main(){
    init_fac();

    cin >> h >> w >> n;
    vector<int> cov_r(h, 0);
    vector<int> cov_c(w, 0);
    for(int i = 0; i < n; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--, r2--, c2--;
        cov_r[r1] = cov_r[r2] = 1;
        cov_c[c1] = cov_c[c2] = 1;
    }
    auto dp1 = calc(cov_r);
    auto dp2 = calc(cov_c);
    int rem1 = dp1.size() - 1;
    int rem2 = dp2.size() - 1;
    ll res = 0;
    for(int i = 0; i <= rem1; i++) {
        for(int j = 0; j <= rem2; j++) {
//            cout << i << ", " << j << ": " << dp1[i] * comb(rem1 - i * 2, j) % mod * dp2[i] % mod * comb(rem2 - i * 2, j) % mod << endl;
            res += 1LL * dp1[i] * comb(rem1 - i * 2, j) % mod * dp2[j] % mod * comb(rem2 - j * 2, i) % mod * fac[i] % mod * fac[j];
            res %= mod;
        }
    }
    cout << res << '\n';

}