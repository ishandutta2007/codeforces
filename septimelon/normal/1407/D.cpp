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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e11;
const ll INFL = 1e16;
const int INF = 1e9 + 7;

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

ll add(ll& a, ll b) {
    ll ans = a + b;
    while (ans >= MOD) {
        ans -= MOD;
    }
    return ans;
}

ll sub(ll& a, ll b) {
    return add(a, MOD - b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> inc({ 0 }), dec({ 0 });
    vector<int> steps(n, 0);
    for (int i = 1; i < n; ++i) {
        steps[i] = INF;
        while (inc.size() > 0 && a[inc.back()] > a[i]) {
            if (a[i - 1] > a[i]) {
                steps[i] = min(steps[i], steps[inc.back()] + 1);
            }
            inc.pop_back();
        }
        while (dec.size() > 0 && a[dec.back()] < a[i]) {
            if (a[i - 1] < a[i]) {
                steps[i] = min(steps[i], steps[dec.back()] + 1);
            }
            dec.pop_back();
        }
        if (inc.size() > 0) {
            steps[i] = min(steps[i], steps[inc.back()] + 1);
            if (a[inc.back()] == a[i]) {
                inc.pop_back();
            }
        }
        if (dec.size() > 0) {
            steps[i] = min(steps[i], steps[dec.back()] + 1);
            if (a[dec.back()] == a[i]) {
                dec.pop_back();
            }
        }
        inc.push_back(i);
        dec.push_back(i);
    }

    cout << steps.back() << "\n";

    return 0;
}