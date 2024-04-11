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
        rep(i, n)
            cin >> a[i];
        int mx = 0, f = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (i < n && a[i] != a[i + 1] - 1 && n - i - 1 != mx)
                f = 1;
            mx = max(mx, a[i]);
        }
        if (f)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}