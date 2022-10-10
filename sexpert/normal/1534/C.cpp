#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const int MAXN = 4e5 + 10;
int to[MAXN], a[MAXN], vi[MAXN];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        vi[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        to[x] = i;
    }
    ll ans = 1;
    for(int i = 1; i <= n; i++) {
        if(vi[i])
            continue;
        ans = (ans + ans) % MOD;
        int cur = i, st = 0;
        do {
            vi[cur] = 1;
            cur = to[a[cur]];
            st ^= 1;
        } while(!vi[cur]);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}