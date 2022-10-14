#define __GLIBCXX_DEBUG

#include <iostream>
#include <iomanip>
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
#include <random>
#include <queue>
#include <bitset>

#define pb push_back
#define int long long
#define dbl long double
#define str string
using namespace std;
const int M = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n = 9;
        vector<string> F(n);
        for (int i = 0; i < n; i++) cin >> F[i];
        vector<pair<int,int>> saaas = {{0, 0}, {1, 3}, {2, 6}, {3, 1}, {4, 4}, {5, 7}, {6, 2}, {7, 5}, {8, 8}};
        for (auto p : saaas) {
            F[p.first][p.second] += 1;
            if (F[p.first][p.second] == '9' + 1) F[p.first][p.second] = '1';
        }
        for (auto s : F) {
            cout << s << '\n';
        }

    }
}