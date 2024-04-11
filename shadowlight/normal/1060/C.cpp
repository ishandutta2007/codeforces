#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

vector <vector <ll> > sum, a;

struct t {
    ll a, l, r;
};

bool operator<(t a, t b) {
    if (a.a == b.a) {
        return a.r - a.l > b.r - b.l;
    }
    return a.a < b.a;
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
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n), b(m);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector <t> la(n + 1, {INF, INF, INF}), lb(m + 1, {INF, INF, INF});
    la[0] = {0, -1, -1};
    lb[0] = {0, -1, -1};
    for (ll i = 0; i < n; i++) {
        ll sum = 0;
        for (ll j = i; j < n; j++) {
            sum += a[j];
            la[j - i + 1] = min(la[j - i + 1], {sum, i, j});
        }
    }
    for (ll i = 0; i < m; i++) {
        ll sum = 0;
        for (ll j = i; j < m; j++) {
            sum += b[j];
            lb[j - i + 1] = min(lb[j - i + 1], {sum, i, j});
        }
    }
    for (ll i = n - 1; i >= 0; i--) {
        la[i] = min(la[i], la[i + 1]);
    }
    for (ll i = m - 1; i >= 0; i--) {
        lb[i] = min(lb[i], lb[i + 1]);
    }
    ll x;
    cin >> x;
    ll l = 0, r = INF;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        ll len2 = m;
        bool can = false;
        for (ll len1 = 1; len1 <= n; len1++) {
            while (la[len1].a * lb[len2].a > x) {
                len2--;
            }
            if (len1 * len2 >= mid) {
                can = true;
                break;
            }
        }
        if (can) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << "\n";
//    ll len2 = m;
//    bool can = false;
//    for (ll len1 = 1; len1 <= n; len1++) {
//        while (la[len1].a * lb[len2].b > x) {
//            len2--;
//        }
//        if (len1 * len2 > mid) {
//            cout << la[len1].l + 1 << " " << la[len1].r + 1 << " " << lb[len2].l + 1 << " " << lb[len2].r + 1 << "\n";
//            return 0;
//        }
//    }
}