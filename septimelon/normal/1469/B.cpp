#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

//#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e18;
const ll INF = 1e9 + 7;
const ld PI = acos(-1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> apre(n);
        ll maxpa = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            apre[i] = a[i];
            if (i > 0) {
                apre[i] += apre[i - 1];
            }
            maxpa = max(maxpa, apre[i]);
        }
        int m;
        cin >> m;
        vector<ll> b(m);
        vector<ll> bpre(m);
        ll maxpb = 0;
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
            bpre[i] = b[i];
            if (i > 0) {
                bpre[i] += bpre[i - 1];
            }
            maxpb = max(maxpb, bpre[i]);
        }

        cout << maxpa + maxpb << "\n";
    }
}