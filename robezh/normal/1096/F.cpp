#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)2e5 + 500;
const ll mod = 998244353;

int n, num[N];
ll psum[N], ssum[N];
int cnt[N], scnt[N];
ll fac[N], facinv[N];
ll inv[N];
ll res = 0;

int bit[N];
int pn = 0;
P p[N];

int get(int i){
    int ans = 0;
    while(i){ans += bit[i]; i -= (i&-i);}
    return ans;
}

int add(int i, int val){
    while(i < N){bit[i] += val; i += (i&-i);}
}


ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll iv(ll x){
    return fp(x, mod - 2);
}


int main(){
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &num[i]);
        if(num[i] != -1){
            cnt[num[i]] ++;
            p[pn].first = num[i];
            p[pn].second = i;
            pn++;
        }
    }
    for(int i = 1; i <= n; i++) cnt[i] = 1 - cnt[i];
    for(int i = 1; i <= n; i++) scnt[i] = scnt[i-1] + cnt[i];
    for(int i = 1; i <= n; i++) psum[i] = psum[i-1] + (num[i] == -1);
    for(int i = n; i >= 1; i--) ssum[i] = ssum[i+1] + (num[i] == -1);

    for(int i = 1; i <= n; i++){
        if(num[i] != -1){
            res += ssum[i] * iv(psum[i] + ssum[i]) % mod * scnt[num[i]-1];
            res += psum[i] * iv(psum[i] + ssum[i]) % mod * (scnt[n] - scnt[num[i]]);
        }
    }
//    cout << res << endl;

    int m1cnt = scnt[n];
    res += 1LL * m1cnt * (m1cnt - 1) % mod * inv[4] % mod;

    sort(p, p + pn);
    for(int i = pn - 1; i >= 0; i--){
        res += get(p[i].second);
        add(p[i].second, 1);
    }

    cout << (res % mod + mod) % mod << endl;

}