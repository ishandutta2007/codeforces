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

const int M = 1000001;
ll b[M], isp[M];


int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)
        cin >> a[i];
    sort(all(a));
    vector<pair<ll, ll>> c;
    ll lx = -1;
    for (ll i : a) {
        if (i == lx)
            c.back().second++;
        else {
            lx = i;
            c.push_back({i, 1});
        }
    }
    ll l = max(a[0] - n, 1ll), r = a[0] + n;
    vector<ll> lp;
    rep(i, r - l + 1)
        b[i] = l + i;
    for (ll i = 2; i < M; i++) {
        if (isp[i])
            continue;
        for (ll j = i * i; j < M; j += i)
            isp[j] = 1;
        ll f = (l + i - 1) / i * i;
        if (f > r)
            continue;
        for (; f <= r; f += i)
            while (b[f - l] % i == 0)
                b[f - l] /= i;
        lp.push_back(i);
    }
    rep(i, r - l + 1)
        if (b[i] > 1)
            lp.push_back(b[i]);
    ll ans = n, ca;
    for (ll i : lp) {
        ca = 0;
        for (auto &pp : c) {
            if (pp.first <= i)
                ca += (i - pp.first) * pp.second;
            else
                ca += min(pp.first % i, i - pp.first % i) * pp.second;
            if (ca > ans)
                break;
        }
        ans = min(ans, ca);
    }
    cout << ans;
}