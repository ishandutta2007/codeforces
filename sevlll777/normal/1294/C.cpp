#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unrool-loops")
#pragma GCC optimize("no-stack-limit")
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
#define tupint tuple<int, int, int>
#define tupint2 tuple<int, int, int, int>
#define str string
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a = 1, b = 1, c = 1;
        for (int d = 2; d * d <= n; d++) {
            if (n % d == 0) {
                n /= d;
                a = d;
                break;
            }
        }
        for (int d = a + 1; d * d <= n; d++) {
            if (n % d == 0) {
                n /= d;
                b = d;
                break;
            }
        }
        c = n;
        if (c >= 2 && a != 1 && b != 1 && c > b) {
            cout << "YES\n";
            cout << a << ' ' << b << ' ' << c << '\n';
        } else {
            cout << "NO\n";
        }
    }

}