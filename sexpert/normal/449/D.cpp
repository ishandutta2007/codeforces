#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll cnt[1 << 20];
ll po[1 << 20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    po[0] = 1;
    for(int i = 1; i < (1 << 20); i++)
        po[i] = (po[i - 1] * 2) % MOD;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(int i = 0; i < 20; i++) {
        for(int ms = (1 << 20) - 1; ms >= 0; ms--) {
            if((ms & (1 << i)) == 0)
                cnt[ms] += cnt[ms ^ (1 << i)];
        }
    }
    ll ans = 0;
    for(int ms = 0; ms < (1 << 20); ms++) {
        if(__builtin_popcount(ms) % 2)
            ans = (ans - po[cnt[ms]]) % MOD;
        else
            ans = (ans + po[cnt[ms]]) % MOD;
    }
    cout << (ans + MOD) % MOD << '\n';
}