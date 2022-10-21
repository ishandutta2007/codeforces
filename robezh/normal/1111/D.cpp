#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50, A = 128;
const ll mod = (int)1e9 + 7;

int n;
int cnt[A];
string alp;
string str;
ll res[A][A];
ll dp[N];
ll fac[N], facinv[N];
ll inv[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

void add(char c) {
    if(cnt[c] == 0) return ;
    for(int t = n / 2; t >= cnt[c]; t--)
        dp[t] += dp[t - cnt[c]];
}

void del(char c) {
    if(cnt[c] == 0) return ;
    for(int t = cnt[c]; t <= n / 2; t++)
        dp[t] -= dp[t - cnt[c]];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;
    for(char i = 'a'; i <= 'z'; i++) alp.push_back(i);
    for(char i = 'A'; i <= 'Z'; i++) alp.push_back(i);

    cin >> str;
    n = str.length();
    for(char c : str) cnt[c] ++;
    ll W = fac[n / 2] * fac[n / 2] % mod;
    for(char c : alp) W *= facinv[cnt[c]], W %= mod;

    dp[0] = 1;
    for(char c : alp) add(c);
    for(int i = 0; i < alp.size(); i++) {
        for(int j = i; j < alp.size(); j++) {
            char c1 = alp[i], c2 = alp[j];
            del(c1);
            if(c1 != c2) del(c2);
            res[c1][c2] = res[c2][c1] = (dp[n / 2] % mod + mod) % mod;
            add(c1);
            if(c1 != c2) add(c2);
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int i, j; cin >> i >> j; i--, j--;
        cout << res[str[i]][str[j]] * W * 2 % mod << "\n";
    }
}