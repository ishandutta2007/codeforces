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
	ll n, k, fx;
    cin >> n;
    vector<pair<ll, ll>> a;
    ll ans = n * n;
    rep(i, n) {
        cin >> k >> fx;
        ll lx = fx, x, f = 0;
        rep(j, k - 1) {
            cin >> x;
            if (x > lx)
                f = 1;
            lx = x;
        }
        if (!f)
            a.push_back({lx, fx});        
    }
    sort(all(a));
    for (auto &pp : a) {
        ans -= a.end() - lower_bound(all(a), make_pair(pp.second, 0ll));
    }
    cout << ans;
}