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
    ll n, d, m, s = 0, x;
    cin >> n >> d >> m;
    vector<ll> a, b;
    rep(i, n) {
        cin >> x;
        if (x > m)
            a.push_back(x);
        else
            b.push_back(x);
    }
    sort(rall(a));
    sort(rall(b));
    vector<ll> pa(a.size() + 1), pb(b.size() + 1);
    rep(i, a.size())
        pa[i + 1] = pa[i] + a[i];
    rep(i, b.size())
        pb[i + 1] = pb[i] + b[i];
    rep(i, a.size() + 1) {
        if (i * (d + 1) - d > n)
            continue;
        s = max(s, pa[i] + pb[min((ll) b.size(), n - (i * (d + 1) - d))]);
    }
    cout << s;
}