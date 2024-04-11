#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

vector<ll> f(ll x, ll y) {
    vector<ll> ans = {0, 0, 0};
    ans[0] = 1LL<<51;
    if (x % 2) ans[0]++;
    x += ans[0];
    y ^= ans[0];
    ll d = y * 2 - x;
    ans[1] = ans[2] = d / 2;
    return ans;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        ll x = 0, y = 0;
        while (N--) {
            ll a; scanf("%lld", &a);
            x += a;
            y ^= a;
        }
        vector<ll> ans = f(x, y);
        cout << 3 << endl;
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
        x += ans[0] + ans[1] + ans[2];
        y ^= ans[0] ^ ans[1] ^ ans[2];
        if (x != y * 2) cerr << "ERR" << endl;
    }
}