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

const ll MOD = 998244353;
const ld EPS = 1e-11;
const ll INFL = 2e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

ll get_pair_sum(int i, int j) {
    ll a1, a2;
    cout << "and " << i + 1 << " " << j + 1 << endl;
    cin >> a1;
    cout << "or " << i + 1 << " " << j + 1 << endl;
    cin >> a2;
    return a1 + a2;
}

void finish(ll sum_with_f, ll sum_with_s, ll sum_without) {
    //cout << sum_with_f << " " << sum_with_s << " " << sum_without << endl;
    cout << "finish " << (sum_with_f - sum_without + sum_with_s) / 2LL << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<pair<ll, int>> sums(n - 1);
    for (int i = 1; i < n; ++i) {
        sums[i - 1] = { get_pair_sum(0, i), i };
    }

    sort(sums.begin(), sums.end());

    if (k == 1 || k == n) {
        ll dias = get_pair_sum(sums[0].second, sums.back().second);
        if (k == 1) {
            if (dias < sums.back().first) {
                finish(sums[0].first, dias, sums.back().first);
            }
            else {
                finish(sums[0].first, sums.back().first, dias);
            }
        }
        else {
            if (dias > sums[0].first) {
                finish(dias, sums.back().first, sums[0].first);
            }
            else {
                finish(sums[0].first, sums.back().first, dias);
            }
        }
        return 0;
    }

    int cl = sums[k - 2].second, cr = sums[k - 1].second;
    ll mids = get_pair_sum(cl, cr);
    if (mids < sums[k - 2].first) {
        finish(sums[k - 1].first, mids, sums[k - 2].first);
    }
    else if (mids < sums[k - 1].first) {
        finish(sums[k - 2].first, sums[k - 1].first, mids);
    }
    else {
        finish(sums[k - 2].first, mids, sums[k - 1].first);
    }

    return 0;
}