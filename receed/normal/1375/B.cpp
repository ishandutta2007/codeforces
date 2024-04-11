#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, m, x;
    cin >> t;
    rep(z, t) {
        cin >> n >> m;
        int f = 0;
        rep(i, n)
            rep(j, m) {
                cin >> x;
                int d = (i > 0) + (j > 0) + (i < n - 1) + (j < m - 1);
                if (x > d)
                    f = 1;
            }
        if (f) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        rep(i, n) {
            rep(j, m) {
                int d = (i > 0) + (j > 0) + (i < n - 1) + (j < m - 1);
                cout << d << ' ';
            }
            cout << '\n';
        }
    }
}