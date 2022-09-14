#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cassert>
#include <bitset>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;
using ld = long double;
using namespace std;

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ll n, ans = 0, x;
    cin >> n;
    map<ll, ll> m;
    rep(i, n) {
        cin >> x;
        m[x - i] += x;
    }
    for (auto &pp : m)
        ans = max(ans, pp.second);
    cout << ans;
}