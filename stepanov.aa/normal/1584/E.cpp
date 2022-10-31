#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <array>
#include <random>
#include <ctime>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>


using namespace std;


#define int long long
#define ll long long
#define ld long double
#define flt double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define emb emplace_back


int bin_find1(vector<pair<ll, int>>& a, ll x) {
    int l = -1;
    int r = a.size();
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (a[m].first > x) {
            l = m;
        } else {
            r = m;
        }
    }
    return a[l].second;
}


int bin_find2(vector<pair<ll, int>>& a, ll x) {
    int l = -1;
    int r = a.size();
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (a[m].first < x) {
            l = m;
        } else {
            r = m;
        }
    }
    return a[l].second;
}


int bin_find3(vector<int>& a, int x) {
    int l = -1;
    int r = a.size();
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (a[m] < x) {
            r = m;
        } else {
            l = m;
        }
    }
    return (int)(a.size()) - r;
}


int n;
vector<ll> a;


ll solve1(vector<ll> &a) {
    if (a.size() == 0) {
        return 0;
    }
    int n = a.size();
    vector<ll> p;
    p.resize(n + 1);
    p[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            p[i + 1] = p[i] - a[i];
        } else {
            p[i + 1] = p[i] + a[i];
        }
    }
    vector<int> b(n);
    vector<pair<ll, int>> mxs, mns;
    mxs.push_back(make_pair((ll)(1e18), n));
    mns.push_back(make_pair((ll)(-1e18), n));
    for (int i = n - 1; i >= 0; --i) {
        if (i & 1) {
            ll x = p[i + 1];
            while (x >= mxs.back().first) {
                mxs.pop_back();
            }
            mxs.push_back(make_pair(x, i));
        } else {
            ll x = p[i + 1];
            while (x <= mns.back().first) {
                mns.pop_back();
            }
            mns.push_back(make_pair(x, i));
            ll s = p[i];
            b[i] = min(bin_find1(mxs, s), bin_find2(mns, s));
        }
    }
    unordered_map<int, vector<int>> mp;
    ll res = 0;
    for (int i = n - 1; i >= 0; --i) {
        mp[p[i + 1]].push_back(i);
        ll s = p[i];
        res += bin_find3(mp[s], b[i]);
    }
    return res;
}


ll solve() {
    vector<ll> b(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        b[i] = a[i + 1];
    }
    return solve1(a) + solve1(b);
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << solve() << "\n";
    }
    return 0;
}