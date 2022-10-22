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

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> c[i] >> d[i];
    }

    vector<int> mdy(1000003, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (c[j] >= a[i] && d[j] >= b[i]) {
                mdy[c[j] - a[i] + 1] = max(mdy[c[j] - a[i] + 1], d[j] - b[i] + 1);
            }
        }
    }

    for (int i = 1000001; i >= 0; --i) {
        mdy[i] = max(mdy[i], mdy[i + 1]);
    }

    int ans = INF;
    for (int i = 1000001; i >= 0; --i) {
        //cout << i << "," << mdy[i + 1] << "\n";
        ans = min(ans, i + mdy[i + 1]);
    }

    cout << ans << "\n";

    return 0;
}