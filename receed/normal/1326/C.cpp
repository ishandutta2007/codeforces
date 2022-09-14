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

const int MOD = 998244353;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, k, ans = 0, c = 1;
    cin >> n >> k;
    vector<pair<ll, ll>> a(n);
    rep(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(rall(a));
    vector<ll> b;
    rep(i, k) {
        ans += a[i].first;
        b.push_back(a[i].second);
    }
    sort(all(b));
    rep(i, k - 1)
        c = c * (b[i + 1] - b[i]) % MOD;
    cout << ans << ' ' << c;
}