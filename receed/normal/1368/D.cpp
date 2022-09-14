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
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, x, ans = 0, y;
    cin >> n;
    vector<pair<ll, ll>> a, b;
    rep(i, n) {
        cin >> x;
        ll f = 0;
        b.clear();
        for (auto &p : a) {
            if (f || (x & p.first) == p.first) {
                if (!b.empty() && b.back().first == p.first)
                    b.back().second += p.second;
                else
                    b.push_back(p);
            }
            else if ((x & p.first) == x) {
                if (!b.empty() && b.back().first == x)
                    b.back().second++;
                else
                    b.push_back({x, 1});
                f = 1;
                if (!b.empty() && b.back().first == p.first)
                    b.back().second += p.second;
                else
                    b.push_back(p);
            }
            else {
                y = (x & p.first);
                p.second--;
                if (!b.empty() && b.back().first == y)
                    b.back().second++;
                else
                    b.push_back({y, 1});
                x = (x | p.first);
                if (p.second)
                    b.push_back(p);
            }
        }
        if (!f) {
            if (!b.empty() && b.back().first == x)
                b.back().second++;
            else
                b.push_back({x, 1});
        }
        a = b;
    }
    for (auto &p : a)
        ans += p.first * p.first * p.second;
    cout << ans;
}