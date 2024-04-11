#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 50;
const ll mod = 998244353;

int n, num[N];
ll fac[N], facinv[N];
ll inv[N];
string str;
int pre[N], suf[N];
ll bin[2][N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

ll add(ll a, ll b) {
    a += b;
    if(a >= mod) a -= mod;
    return a;
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

    cin >> str;
    n = str.length();
    str = " " + str;
    int cntq = 0;
    for(char c : str) if(c == '?') cntq++;
    for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + (str[i] == '(');
    for(int i = n; i >= 1; i--) suf[i] = suf[i+1] + (str[i] == ')');

    for(int d = 0; d < 2; d++) {
        int cnt = cntq - 1 + d;
        if(cnt < 0) continue;
        for(int i = cnt; i >= 0; i--) bin[d][i] = add(bin[d][i+1], comb(cnt, i));
    }
    int cq = 0;
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        if(str[i] == '?') {
            cq++;
            res = add(res, bin[0][max(0, pre[i] + cq - suf[i+1])]);
        } else if(str[i] == '(') {
            res = add(res, bin[1][max(0, pre[i] + cq - suf[i+1])]);

        }
    }
    cout << res << '\n';
}