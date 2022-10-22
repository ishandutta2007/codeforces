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

ll geta(vector<int> n, vector<vector<ll>> a, vector<ll> sum) {
    ll cura = abs(sum[0] - a[0][0] - a[1][0]);
    cura -= a[0][0];
    cura += sum[2];
    cura += sum[1] - a[1][0];
    return cura;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> n(3);
    cin >> n[0] >> n[1] >> n[2];
    vector<vector<ll>> a(3);
    vector<ll> sum(3, 0);
    for (int i = 0; i < 3; ++i) {
        a[i].resize(n[i]);
        for (int j = 0; j < n[i]; ++j) {
            cin >> a[i][j];
            sum[i] += a[i][j];
        }
        sort(a[i].begin(), a[i].end());
    }

    ll besta = geta(n, a, sum);
    for (int i = 0; i < 3; ++i) {
        swap(n[1], n[2]);
        swap(a[1], a[2]);
        swap(sum[1], sum[2]);
        besta = max(besta, geta(n, a, sum));
        swap(n[0], n[1]);
        swap(a[0], a[1]);
        swap(sum[0], sum[1]);
        besta = max(besta, geta(n, a, sum));
    }

    cout << besta << "\n";
}