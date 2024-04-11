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
	ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    rep(i, n)
        cin >> a[i].first;
    rep(i, n)
        cin >> a[i].second;
    ll ans = 0, mp = 0;
    sort(all(a));
    multiset<ll> s;
    for (auto &pp : a) {
        while (mp < pp.first && !s.empty()) {
            ans += *--s.end() * mp;
            mp++;
            s.erase(--s.end());
        }
        mp = max(mp, pp.first);
        ans -= pp.second * pp.first;
        s.insert(pp.second);
    }
    while (!s.empty()) {
        ans += *--s.end() * mp;
        mp++;
        s.erase(--s.end());
    }
    cout << ans;
}