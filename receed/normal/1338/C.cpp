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

int q[3][4] = {{0, 1, 2, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}};

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll t, n;
    cin >> t;
    rep(z, t) {
        cin >> n;
        ll mp = 1;
        while (n >= mp * 4)
            mp *= 4;
        ll d = (n - mp) % 3, k = (n - mp) / 3, ans = 0;
        for (ll pp = 1; k; pp *= 4, k /= 4)
            ans += q[d][k % 4] * pp;
        ans += (d + 1) * mp;
        cout << ans << '\n';
    }
}