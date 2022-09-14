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

const int N = 100001;
ll c0[N], c1[N], d0[N], d1[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    ll x, y, n;
    cin >> s >> x >> y;
    n = s.size();
    if (x < y) {
        swap(x, y);
        rep(i, n) {
            if (s[i] == '0')
                s[i] = '1';
            else if (s[i] == '1')
                s[i] = '0';
        }
    }
    rep(i, n) {
        c0[i + 1] = c0[i] + (s[i] == '0');
        c1[i + 1] = c1[i] + (s[i] == '1');
    }
    vector<int> li;
    ll ans = 0;
    rep(i, n) {
        if (s[i] == '?')
            li.push_back(i);
        else if (s[i] == '0')
            ans += y * c1[i];
        else
            ans += x * c0[i];
    }
    rep(i, li.size()) {
        d1[i + 1] = d1[i] + c0[li[i]] * x + (c0[n] - c0[li[i]]) * y;
        int j = li.size() - 1 - i;
        d0[i + 1] = d0[i] + c1[li[j]] * y + (c1[n] - c1[li[j]]) * x;
    }
    ll res = 1e18;
    rep(i, li.size() + 1)
        res = min(res, d1[i] + d0[li.size() - i] + y * (ll) i * (ll) (li.size() - i));
    cout << ans + res;
}