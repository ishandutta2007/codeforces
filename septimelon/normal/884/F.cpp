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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i];
    }

    map<char, int> paired;
    map<char, vector<int>> legal;
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] == s[n - i - 1]) {
            ans -= min(a[i], a[n - i - 1]);
            if (paired.count(s[i]) == 0) {
                paired[s[i]] = 1;
            }
            else {
                ++paired[s[i]];
            }
        }
        else {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == s[i] || c == s[n - i - 1]) {
                    continue;
                }
                if (legal.count(c) == 0) {
                    legal[c] = { min(a[i], a[n - i - 1]) };
                }
                else {
                    legal[c].push_back(min(a[i], a[n - i - 1]));
                }
            }
        }
    }

    int needp = 0;
    vector<pair<int, char>> ccou;
    for (auto it = paired.begin(); it != paired.end(); ++it) {
        ccou.push_back({ it->second, it->first });
        needp += it->second;
    }
    sort(ccou.begin(), ccou.end());
    for (char c = 'a'; c <= 'z'; ++c) {
        if (legal.count(c) == 0) {
            legal[c] = { INF };
        }
        else {
            legal[c].push_back(INF);
            sort(legal[c].begin(), legal[c].end());
        }
    }

    if (ccou.size() > 0 && ccou.back().first * 2 >= needp) {
        for (int i = 0; i < ccou.back().first * 2 - needp; ++i) {
            ans -= legal[ccou.back().second][i];
        }
    }
    cout << ans << "\n";

    return 0;
}