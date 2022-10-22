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

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    vector<pair<int, int>> begs;
    int lastw = -1;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && s[i] == 'W' && s[i - 1] == 'L') {
            if (lastw >= 0) {
                begs.push_back({ i - lastw - 1, lastw + 1 });
            }
        }
        if (s[i] == 'W') {
            lastw = i;
        }
    }
    sort(begs.begin(), begs.end());

    for (int i = 0; i < begs.size(); ++i) {
        for (int j = 0; j < begs[i].first; ++j) {
            if (k == 0) {
                break;
            }
            s[begs[i].second + j] = 'W';
            --k;
        }
    }

    for (int i = lastw + 1; i < n; ++i) {
        if (s[i] == 'L') {
            if (k == 0) {
                break;
            }
            s[i] = 'W';
            --k;
        }
    }
    
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'L') {
            if (k == 0) {
                break;
            }
            s[i] = 'W';
            --k;
        }
    }
    
    lastw = -2;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W') {
            if (lastw == i - 1) {
                ans += 2;
            }
            else {
                ++ans;
            }
            lastw = i;
        }
    }
    //cout << s << " ";
    cout << ans << "\n";
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