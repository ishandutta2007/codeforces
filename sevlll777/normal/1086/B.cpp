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
#include <bitset>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, s;
    cin >> n >> s;
    vector<int> cnt(n);
    int a = 0;
    for (int _ = 0; _ < n - 1; _++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        cnt[x]++;
        cnt[y]++;
    }
    for (int v = 0; v < n; v++) a += (cnt[v] == 1);
    cout << fixed;
    cout << (2.0 * s) / a << '\n';
}