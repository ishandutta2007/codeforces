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
        int n;
        cin >> n;
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            x--;
            cnt[x]++;
        }
        int lol = 0;
        int C = 0;
        for (auto p : cnt) C += (p > 0);
        for (auto p : cnt) {
            for (int B = 0; B < p; B++) {
                lol = max(lol, min(B, C));
            }
            lol = max(lol, min(p, C - 1));
        }
        cout << min(lol, n / 2) << '\n';

    }
}