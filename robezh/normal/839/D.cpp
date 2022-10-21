#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200050, M = (int)1e6 + 50;
const int mod = (int)1e9 + 7;

int n;
ll pw2[M], tot[M];
ll cnt[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pw2[0] = 1;
    for(int i = 1; i < M; i++) pw2[i] = pw2[i-1] * 2 % mod;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a; cnt[a] ++;
    }
    for(int i = 2; i < M; i++) {
        for(int j = i * 2; j < M; j += i) {
            cnt[i] += cnt[j];
            if(cnt[i] > mod) cnt[i] -= mod;
        }
    }
    for(int i = M - 1; i >= 2; i--) {
        if(cnt[i] == 0) continue;
        tot[i] = cnt[i] * (pw2[cnt[i]-1]) % mod;
        for(int j = i * 2; j < M; j += i) {
            tot[i] -= tot[j];
            if(tot[i] < 0) tot[i] += mod;
        }
    }
    ll res = 0;
    for(int i = 2; i < M; i++) res += tot[i] * i % mod;
    res %= mod;
    cout << res << endl;

}