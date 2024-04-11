#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7;
const int N = 5005, M = 500;

int n;
string str, s;
ll dp[N][N];
int la[M];
ll sumla[N];
ll fac[N], facinv[N];
ll inv[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    init_fac();

    cin >> n;
    cin >> str;
    for(char c : str) {
        if(s.empty() || c != s.back()) s.push_back(c);
    }
    str = s;
    str = " " + str;
    ll res = 0;
    for(int i = 1; i < str.length(); i++) {
        for(int j = 1; j <= n + 1; j++) {
            if(j == 1) dp[i][j] = 1;
            else {
                dp[i][j] = (sumla[j-1] - dp[la[str[i]]][j-1]) % mod;
                sumla[j-1] += -dp[la[str[i]]][j-1] + dp[i][j-1];
                sumla[j-1] %= mod;
            }
        }
        la[str[i]] = i;
    }
    for(int len = 1; len <= n; len++) {
        res += comb(n - 1, len - 1) * sumla[len] % mod;
        res %= mod;
    }
    if(res < 0) res += mod;
    cout << res << endl;



}