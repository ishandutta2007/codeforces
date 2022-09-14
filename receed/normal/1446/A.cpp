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
    ll t, n, w;
    cin >> t;
    rep(z, t) {
        cin >> n >> w;
        vector<pair<ll, ll>> ww(n);
        rep(i, n) {
            cin >> ww[i].first;
            ww[i].second = i + 1;
        }
        sort(rall(ww));
        ll cs = 0;
        vector<ll> ans;
        for (auto &i : ww)
            if (cs + i.first <= w) {
                cs += i.first;
                ans.push_back(i.second);
            }
        if (cs * 2 < w)
            cout << "-1\n";
        else {
            cout << ans.size() << '\n';
            for (ll i : ans)
                cout << i << ' ';
            cout << '\n';
        }
    }
}