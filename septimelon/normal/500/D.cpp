#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF = 1000000009;
const ll INFL = 1e18 + 5LL;
const ld EPS = 1e-11;

int look(int v, int from, vector<ll>& llen, const vector<vector<pair<int, int>>>& r) {
    int here = 1;
    for (int i = 0; i < r[v].size(); ++i) {
        if (r[v][i].first == from) {
            continue;
        }
        llen[r[v][i].second] = look(r[v][i].first, v, llen, r);
        here += llen[r[v][i].second];
    }
    return here;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> a(n - 1), b(n - 1), l(n - 1), llen(n - 1);
    vector<vector<pair<int, int>>> r(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i] >> b[i] >> l[i];
        --a[i];
        --b[i];
        r[a[i]].push_back({ b[i], i });
        r[b[i]].push_back({ a[i], i });
    }

    for (int i = 0; i < n; ++i) {
        if (r[i].size() == 1) {
            look(i, -1, llen, r);
            break;
        }
    }

    ll tot = 0;
    for (int i = 0; i < n - 1; ++i) {
        tot += l[i] * llen[i] * (n - llen[i]);
    }

    int q;
    cin >> q;
    for (int iii = 0; iii < q; ++iii) {
        int ri, w;
        cin >> ri >> w;
        --ri;
        tot += (w - l[ri]) * llen[ri] * (n - llen[ri]);
        l[ri] = w;
        ld ans = tot * 3. / (n * (n - 1) / 2);
        cout << setprecision(9) << ans << "\n";
    }

    return 0;
}