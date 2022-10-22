#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

pair <ll, ll> cnt(ll x1, ll y1, ll x2, ll y2) {
    if (x2 < x1 || y2 < y1) {
        return {0, 0};
    }
    ll all = (x2 - x1 + 1) * (y2 - y1 + 1);
    ll a = all / 2, b = all - a;
    if ((x1 + y1) % 2 == 0) {
        swap(a, b);
    }
    return {a, b};
}

void solve() {
    ll n, m;
    cin >> n >> m;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    ll black = n * m / 2;
    auto t1 = cnt(x1, y1, x2, y2);
    black -= t1.second;
    auto t2 = cnt(x3, y3, x4, y4);
    black += t2.first;
    ll x5 = max(x1, x3), x6 = min(x2, x4);
    ll y5 = max(y1, y3), y6 = min(y2, y4);
    auto t3 = cnt(x5, y5, x6, y6);
    black += t3.second;
    cout << n * m - black << " " << black << "\n";
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++ ) {
        solve();
    }
}