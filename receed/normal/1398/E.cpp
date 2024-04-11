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

set<pair<ll, ll>> s1, s2;
ll k, ct, sm;

void rec() {
    while (s1.size() > k) {
        auto p = *s1.begin();
        sm -= p.first;
        ct -= p.second;
        s2.insert(p);
        s1.erase(s1.begin());
    }
    while (s1.size() < k && !s2.empty()) {
        auto p = *--s2.end();
        sm += p.first;
        ct += p.second;
        s2.erase(--s2.end());
        s1.insert(p);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, t, d, ts = 0;
    cin >> n;
    rep(i, n) {
        cin >> t >> d;
        ts += d;
        if (d > 0) {
            k += t;
            rec();
            if (k > 0 && s1.empty() || !s1.empty() && d > (*s1.begin()).first) {
                s1.insert({d, t});
                ct += t;
                sm += d;
            }
            else
                s2.insert({d, t});
            rec();
        }
        else {
            d *= -1;
            k -= t;
            if (s2.count({d, t}))
                s2.erase({d, t});
            else {
                s1.erase({d, t});
                sm -= d;
                ct -= t;
            }
            rec();
        }
        if (ct < k || k == 0)
            cout << ts + sm << '\n';
        else if (s2.empty())
            cout << ts + sm - (*s1.begin()).first << '\n';
        else
            cout << ts + sm - (*s1.begin()).first + (*--s2.end()).first << '\n';
    }
}