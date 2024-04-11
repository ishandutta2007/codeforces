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
const int M = 1000000007;
vector <pair<int, int>> ANS;

void chuch(int l, int r) {
    if (l > r) return;
    if (l + 1 == r) {
        ANS.pb({l, l + 1});
        return;
    }
    int m = (l + r) / 2;
    chuch(l, m);
    chuch(m + 1, r);
    for (int x = l; x <= m; x++) {
        ANS.pb({x, m + 1 + x - l});
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    if (n<=2) {
        cout << 0;
        exit(0);
    } 
    int kek = (int) floor(log2(n));
    int heh = 1;
    while (kek--) heh *= 2;
    chuch(1, heh);
    chuch(n - heh + 1, n);
    cout << ANS.size() << '\n';
    for (auto p : ANS) {
        cout << p.first << ' ' << p.second << '\n';
    }
}