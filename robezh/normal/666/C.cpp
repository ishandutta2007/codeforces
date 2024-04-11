#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;
const int N = (int)1e5 + 50;
const ll mod = (ll)1e9 + 7;

int q;
string str;
ll dp[N];
int n, num[N];
ll fac[N], facinv[N];
ll inv[N], pw25[N], pw26[N];
vector<P> qr[N];
ll res[N];


ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll comb(int n, int k){
    if(k < 0 || n - k < 0) return 0;
    return fac[n] * facinv[k] % mod * facinv[n - k] % mod;
}

void init_fac() {
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;
    pw25[0] = pw26[0] = 1;
    for(int i = 1; i < N; i++) pw25[i] = pw25[i-1] * 25 % mod, pw26[i] = pw26[i-1] * 26 % mod;
}

void calc_dp(int len) {
    ll sum = 0;
    for(int i = 1; i < N; i++) {
        sum = (sum * 26) % mod;
        if(i >= len) sum += comb(i - 1, len - 1) * pw25[i - len] % mod, sum %= mod;
        dp[i] = sum;
    }
}

int main(){
    init_fac();
    cin >> q;
    cin >> str;
    int q_cnt = 0;
    n = str.length();
    for(int i = 0; i < q; i++) {
        int tp;
        cin >> tp;
        if(tp == 1) {
            cin >> str;
        }
        else {
            int len;
            cin >> len;
            qr[str.length()].push_back({q_cnt++, len});
        }
    }
    for(int i = 1; i < N; i++) {
        if(!qr[i].empty()) {
            calc_dp(i);
            for(auto p : qr[i]) {
                res[p.first] = dp[p.second];
            }
        }
    }
    for(int i = 0; i < q_cnt; i++) cout << res[i] << "\n";


}