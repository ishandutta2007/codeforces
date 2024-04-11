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

    int n;
    cin >> n;

    vector<int> a(n);
    int dif = 0;
    vector<int> lastv(n + 1, -1);
    vector<int> las(n, -1);
    vector<int> nexd(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        las[i] = lastv[a[i]];
        lastv[a[i]] = i;
        if (i > 0 && a[i] != a[i - 1]) {
            nexd[lastv[a[i - 1]]] = i;
        }
        if (i == 0 || a[i] != a[i - 1]) {
            ++dif;
        }
    }

    vector<int> bestd(n, 0);
    for (int i = 1; i < n; ++i) {
        bestd[i] = bestd[i - 1];
        if (a[i] != a[i - 1] && las[i] != -1) {
            bestd[i] = max({ bestd[i], bestd[las[i]] + 1, bestd[nexd[las[i]]] + 1 });
        }
        //cout << bestd[i] << "\n";
    }

    cout << dif - bestd[n - 1] << "\n";

    return 0;
}