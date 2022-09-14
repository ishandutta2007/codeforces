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

ld eps = 1e-8;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, k, x, y, g;
    cin >> n >> k;
    map<pair<ll, ll>, vector<ll>> m;
    rep(i, n) {
        cin >> x >> y;
        if (x == 0 && y == 0)
            continue;
        g = abs(__gcd(x, y));
        m[{x / g, y / g}].push_back(x * x + y * y);
    }
    vector<ld> a;
    for (auto &p : m) {
        sort(all(p.second));
        rep(i, p.second.size())
            a.push_back({sqrt(p.second[i]) * (k - 1 - 2 * ((int) p.second.size() - i - 1))});
    }
    sort(rall(a));
    if (a.size() > k)
        a.resize(k);
    while (!a.empty() && a.back() < -eps)
        a.pop_back();
    ld ans = 0;
    for (ld i : a)
        ans += i;
    int ck = k - (int) a.size();
    if (ck > 0)
        ck--;
    for (auto &p : m)
        if (ck > 0 && k + 1 - 2 * (int) p.second.size() < 0) {
            rep(i, ck)
                ans += sqrt(p.second[i]) * (k - 1 - 2 * (ck - i - 1 + (k + 1) / 2));
        }
    cout << fixed << setprecision(8);
    cout << ans;
}