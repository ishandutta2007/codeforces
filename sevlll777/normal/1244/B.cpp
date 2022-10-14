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
    int ans;
    for (int i = 0; i < q; i++) {
        cin >> n;
        cin >> s;
        ans = -1;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                ans = j;
                break;
            }
        }
        for (int j = n - 1; j >= 0; j--) {
            if (s[j] == '1') {
                ans = min(ans, n - j - 1);
                break;
            }
        }
        if (ans == -1) {
            cout << n << '\n';
        } else {
            cout << 2 * n - 2 * ans << '\n';
        }
    }
}