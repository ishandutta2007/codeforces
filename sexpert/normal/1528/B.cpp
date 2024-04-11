#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10;
const ll MOD = 998244353;
ll ans[MAXN], sans[MAXN], tot[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ans[1] = 1;
    sans[1] = 1;

    for(int i = 1; i < MAXN; i++)
        for(int j = 2 * i; j < MAXN; j += i)
            tot[j]++;

    for(int i = 2; i < MAXN; i++) {
        ans[i] = (sans[i - 1] + tot[i] + 1) % MOD;
        sans[i] = (sans[i - 1] + ans[i]) % MOD;
    }

    int n;
    cin >> n;
    cout << ans[n] << '\n';
}