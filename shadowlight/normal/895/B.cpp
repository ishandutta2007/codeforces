#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll n, x, k;

ll calc(ll l, ll r) {
    ll cnt = r / x - (l - 1) / x;
    return cnt;
}
int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cin >> n >> x >> k;
    vector <ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll b = (a[i] - 1) / x + 1;
        ll l1 = (b + k - 1) * x;
        ll r1 = l1 + x - 1;
        if (!k) {
            l1 = a[i];
            //cout << l1 << " " << r1 << "\n";
            if (l1 > r1) {
                continue;
            }
        }
        ll l = lower_bound(a.begin(), a.end(), l1) - a.begin();
        ll r = upper_bound(a.begin(), a.end(), r1) - a.begin() - 1;
        //cout << l1 << " " << r1 << "\n";
        ans += r - l + 1;
    }
    cout << ans;
}