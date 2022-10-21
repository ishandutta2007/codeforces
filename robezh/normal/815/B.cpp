#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50;
const ll mod = (ll)1e9 + 7;

int n;
vector<int> num;
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

void change(vector<int> &V, bool &sig) {
    vector<int> new_V;
    for(int i = 0; i + 1 < V.size(); i++) {
        if(sig) new_V.push_back((V[i] + V[i+1]) % mod);
        else new_V.push_back((V[i] - V[i+1]) % mod);
        sig = !sig;
    }
    V = new_V;
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

    ll res = 0;
    cin >> n;
    num.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    bool sig = true;
    while(num.size() % 4 != 1) change(num, sig);
    n = num.size();
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            res += comb((n - 1)/ 2, i / 2) * num[i];
            res %= mod;
        }
    }
    cout << (res % mod + mod) % mod << endl;


}