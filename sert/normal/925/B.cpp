#include <bits/stdc++.h>
using namespace std;

void init() {
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}

typedef long long ll;
typedef long double ld;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e6 + 34;

bool go(ll x1, ll x2, vector<pair<ll, int>> &a, bool swp) {
    int n = a.size();
    int sz1 = -1;
    for (int i = 0; i < n; i++) {
        if (sz1 == -1 && (1ll + i) * a[i].first >= x1) {
            sz1 = i + 1;
        }
    }
    if (sz1 == -1) return false;
    int sz2 = -1;
    for (int i = sz1; i < n; i++) {
        if (sz2 == -1 && (i - sz1 + 1ll) * a[i].first >= x2) {
            sz2 = i - sz1 + 1ll;
        }
    }
    if (sz2 == -1) return false;

    if (swp) {
        printf("Yes\n%d %d\n", sz2, sz1);
        for (int i = sz1; i < sz1 + sz2; i++) printf("%d ", a[i].second); printf("\n");
        for (int i = 0; i < sz1; i++) printf("%d ", a[i].second); printf("\n");
    } else {
        printf("Yes\n%d %d\n", sz1, sz2);
        for (int i = 0; i < sz1; i++) printf("%d ", a[i].second); printf("\n");
        for (int i = sz1; i < sz1 + sz2; i++) printf("%d ", a[i].second); printf("\n");
    }

    return true;
}

void solve() {
    int n, x1, x2;
    scanf("%d%d%d", &n, &x1, &x2);
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i].first = x;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    bool r1 = go(x1, x2, a, false);
    bool r2 = false;
    if (!r1) r2 = go(x2, x1, a, true);
    if (!r1 && !r2) {
        printf("No\n");
    }
}

int main() {
    init();
	solve();
	//solve();
	//solve();
	//solve();
    return 0;
}