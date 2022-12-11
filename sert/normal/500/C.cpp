#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const ll N = 1e3 + 7;

pair <ll, pair<ll, ll> > a[N];

ll p[N], ans, q, ps, n, m;
ll b[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        cin >> a[i].second.first;
        a[i].second.second = i;
        a[i].first = 100500;
    }
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
        b[i]--;
        if (a[b[i]].first == 100500)
            a[b[i]].first = i;
    }

    sort(a, a + n);

    for (ll i = 0; i < m; i++) {
        q = b[i];
        ps = 0;
        while (a[ps].ss.ss != q) ps++;
        for (ll j = ps - 1; j >= 0; j--) {
            ans += a[j].ss.ff;
            swap(a[j], a[j + 1]);
        }
    }

    cout << ans;

    return 0;
}