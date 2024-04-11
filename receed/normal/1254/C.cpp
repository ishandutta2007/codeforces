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

ll r;

ll q(int t, int i, int j, int k) {
    cout << t << ' ' << i << ' ' << j << ' ' << k << endl;
    cin >> r;
    return r;
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
	int n;
    cin >> n;
    int p = 2;
    for (int i = 3; i <= n; i++)
        if (q(2, 1, p, i) < 0)
            p = i;
    vector<pair<ll, ll>> a;
    for (int i = 2; i <= n; i++)
        if (p != i)
            a.push_back({q(1, 1, p, i), i});
    sort(all(a));
    ll w = a.back().second;
    a.pop_back();
    deque<ll> ans {1, p};
    for (auto &pp : a) {
        ll v = pp.second;
        if (q(2, 1, w, v) > 0)
            ans.push_front(v);
        else
            ans.push_back(v);
    }
    ans.push_back(w);
    cout << "0 ";
    while (ans[0] != 1) {
        ans.push_back(ans[0]);
        ans.pop_front();
    }
    for (ll i : ans)
        cout << i << ' ';
    cout << endl;
}