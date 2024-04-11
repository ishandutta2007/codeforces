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
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll t, n, x, y, mx, f;
    cin >> t;
    rep(z, t) {
        cin >> n >> x;
        mx = 0;
        f = 0;
        rep(i, n) {
            cin >> y;
            mx = max(mx, y);
            if (y == x)
                f = 1;
        }
        if (f)
            cout << "1\n";
        else
            cout << max((x + mx - 1) / mx, 2ll) << '\n';
    }
}