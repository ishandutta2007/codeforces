#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5005;
const ll mod = 998244353;

int n, num[N];
int nxt[N];
ll dp[N][N], ssum[N][N];
ll inv[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

void calc_inv() {
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
}

int main(){
    calc_inv();
    cin >> n;
    for(int i = 0; i < n; i++) cin >> num[i];
    sort(num, num + n);
    for(int i = 0; i < n; i++) {
        nxt[i] = i;
        while(i < n && num[nxt[i]] == num[i]) nxt[i]++;
    }
    for(int del = n - 1; del >= 0; del--) {
        for(int j = n - 1; j >= 0; j--) {
            if(j != 0 && num[j] == num[j-1]) continue;
            ll cnt = nxt[j] - j;
            dp[del][j] += 1LL * (cnt - 1) * inv[n - del - 1] % mod;
            dp[del][j] += ssum[del+1][nxt[j]] * inv[n - del - 1] % mod;
            ssum[del][j] = (ssum[del][nxt[j]] + (nxt[j] - j) * dp[del][j]) % mod;
            dp[del][j] %= mod;
        }
    }

    ll res = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0 || num[i] != num[i-1]) {
            res = (res + 1LL * (nxt[i] - i) * inv[n] % mod * dp[0][i]) % mod;
        }
    }
    cout << res << endl;

}