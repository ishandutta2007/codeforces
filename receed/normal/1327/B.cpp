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
#include <ext/pb_ds/assoc_container.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n;
    cin >> t;
    rep(z, t) {
        cin >> n;
        vector<int> a(n);
        int p = -1, k, x, y;
        rep(i, n) {
            cin >> k;
            y = -1;
            rep(j, k) {
                cin >> x;
                x--;
                if (!a[x] && y == -1)
                    y = x;
            }
            if (y == -1)
                p = i;
            else
                a[y] = 1;
        }
        if (p == -1) {
            cout << "OPTIMAL\n";
            continue;
        }
        y = -1;
        rep(i, n)
            if (!a[i])
                y = i;
        cout << "IMPROVE\n" << p + 1 << ' ' << y + 1 << '\n';
    }
}