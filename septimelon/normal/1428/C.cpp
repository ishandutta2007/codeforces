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
    string s;
    cin >> s;
    int lb = 0, la = 0, del = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') {
            ++la;
        }
        else {
            if (la > 0) {
                --la;
                del += 2;
            }
            else {
                ++lb;
            }
            if (lb >= 2) {
                lb -= 2;
                del += 2;
            }
        }
    }

    cout << s.size() - del << "\n";
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