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
int a, b, c, d, n, m, k, x, r, l, q, i, j, v1, v2, p, y, w;
string s, t;
const int M = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p >> w >> d;
    x = min(p / w, n);
    int cec = 0;
    while (((p - w * x) % d) > 0 && cec <= d + 100) {
        x--;
        cec++;
    }
    if (cec == d + 101) {
        cout << -1;
    } else {
        y = (p - w * x) / d;
        if (x + y <= n && x >= 0 && y >= 0) {
            cout << x << ' ' << y << ' ' << n - x - y;
        } else {
            cout << -1;
        }
    }
}