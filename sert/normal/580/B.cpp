#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 34;

ll n, cur, ans, bst, d;
pair<ll, ll> a[N];
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        ans += a[i].second;
        while (a[cur].first <= a[i].first - d) {
            ans -= a[cur++].second;
        }
        bst = max(bst, ans);
    }
    cout << bst;

    return 0;
}