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
#define int long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pdi pair<double, int>
#define unmp unordered_map
#define unst unordered_set
#define tupint tuple<int, int, int>
using namespace std;
int a, b, c, d, n, m, k, x, r, l, q, i, j, v1, v2, p, y;
string s, t;
const int M = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a >> b >> c >> d >> k;
        int p1 = (a + c - 1) / c;
        int p2 = (b + d - 1) / d;
        if (p1 + p2 <= k) {
            cout << p1 << ' ' << p2 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}