#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
// #define int short
#define int long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmap unordered_map
#define unset unordered_set
#define tupint tuple<int, int, int>
#define pib pair<int, bool>
#define dbl long double
#define str string
#define psi pair<str, int>
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r, c; cin >> r >> c;
    if (r > 1 && c > 1) {
        vector<vector<int>> ans;
        for (int i = 0; i < r; i++) {
            vector<int> huh;
            for (int j = 0; j < c; j++) {
                huh.pb((c + i + 1) * (j + 1));
            }
            ans.pb(huh);
        }
        for (auto x : ans) {
            for (auto g : x) {
                cout << g << ' ';
            }
            cout << '\n';
        }
    } else if (r == 1 && c == 1) {
        cout << 0;
    } else if (r == 1) {
        for (int i = 2; i < 2 + c; i++) {
            cout << i << ' ';
        }
    } else {
        for (int i = 2; i < 2 + r; i++) {
            cout << i << '\n';
        }
    }
}