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
    cout << fixed << setprecision(12);
	ll n, x;
    cin >> n;
    vector<pair<ll, ll>> a;
    rep(i, n) {
        cin >> x;
        ll cc = 1;
        while (!a.empty() && x * a.back().second < a.back().first * cc) {
            x += a.back().first;
            cc += a.back().second;
            a.pop_back();
        }
        a.push_back({x, cc});
    }
    for (auto &pp : a)
        rep(i, pp.second)
            cout << (ld) pp.first / pp.second << '\n';
}