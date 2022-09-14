#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 200002;
ll a[N], b[N], tc;
map<pair<ll, ll>, ll> m;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, q, ss = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ss += a[i];
    }
    cin >> q;
    ll s, t, u, pu;
    rep(i, q) {
        cin >> s >> t >> u;
        if (m.count({s, t})) {
            pu = m[{s, t}];
            m.erase({s, t});
            b[pu]--;
            if (b[pu] < a[pu])
                tc--;
        }
        if (u != 0) {
            m[{s, t}] = u;
            if (b[u] < a[u])
                tc++;
            b[u]++;
        }
        cout << ss - tc << '\n';
    }
}