#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 34;

int x[N];
pair <ll, ll> a[N];
ll cl, cr, ans;
set<int> sl, sr;
set<int>::iterator it;
int l, r;
ll L[N], R[N];
int n, m, v;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n - 1; i++) {
        a[i].first = abs(x[i] - x[i + 1]);
        a[i].second = i;
    }
    sort(a, a + n - 1);
    sl.insert(1);
    sr.insert(n - 1);
    for (int i = n - 2; i >= 0; i--) {
        v = a[i].second;
        L[i] = *(sl.lower_bound(-v)) + v;
        R[i] = *(sr.lower_bound(v)) - v;
        sl.insert(-v);
        sr.insert(v);
    }


    while (m--) {
        cin >> l >> r;
        l--;
        r -= 2;
        ans = 0;
        for (int i = 0; i < n; i++)
            if (l <= a[i].second && a[i].second <= r) {
                cl = min(L[i], a[i].second - l + 1);
                cr = min(R[i], r - a[i].second + 1);
                ans += cl * cr * a[i].first;
            }
        cout << ans << "\n";
    }

    return 0;
}