#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 34;
ll dif, st, n, k;
pair <ll, ll> a[N];
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);

    for (int i = 1; i < n; i++) {
        dif = a[i].first - a[i - 1].first;
        if (dif >= 15)
            k = !!a[i - 1].second;
        else {
            st = (1ll << (2ll * dif));
            k = (a[i - 1].second + st - 1) / st;
        }
        a[i].second = max(a[i].second, k);
    }
    k = a[n - 1].second;
    st = a[n - 1].first;

    if (k == 1) {
        cout << st + 1;
        return 0;
    }

    while (k > 1) {
        k = (k + 3) / 4;
        st++;
    }
    cout << st;

    return 0;
}