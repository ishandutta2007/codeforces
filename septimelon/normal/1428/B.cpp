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
const ld EPS = 1e-11;
const ll INFL = 1e16;
const int INF = 2e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s += s[0];

    int wt = 0;
    bool isl = false, isr = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '<') {
            isl = true;
        }
        if (s[i] == '>') {
            isr = true;
        }
        if (s[i] == '-' || s[i + 1] == '-') {
            ++wt;
        }
    }

    if (!isl || !isr) {
        cout << n << "\n";
    }
    else {
        cout << wt << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}