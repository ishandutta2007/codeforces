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
const ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vector<ll> f(n), w(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    vector<ll> s(w), m(w), v(f);
    for (int di = 44; di >= 0; --di) {
        if ((k >> di) < 2LL) {
            continue;
        }
        vector<ll> ns(s), nm(m), nv(v);
        for (int i = 0; i < n; ++i) {
            ns[i] += s[v[i]];
            nm[i] = min(nm[i], m[v[i]]);
            nv[i] = v[v[i]];
        }
        if ((k >> di) & 1) {
            for (int i = 0; i < n; ++i) {
                ns[i] += w[nv[i]];
                nm[i] = min(nm[i], w[nv[i]]);
                nv[i] = f[nv[i]];
            }
        }
        s = ns;
        m = nm;
        v = nv;
    }

    for (int i = 0; i < n; ++i) {
        cout << s[i] << " " << m[i] << "\n";
    }

    return 0;
}