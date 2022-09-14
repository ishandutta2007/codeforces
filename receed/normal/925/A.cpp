#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <assert.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <unordered_map>
#include <iomanip>

using namespace std;

typedef long long ll;

const long long BIT = 64;
const long long INF = 1e18;
const long double EPS = 1e-9;
const int MSIZE = 200000;
typedef long double ld;
const int N = 10002;

void solve(){
    ll n, m, cl, ce, v;
    cin >> n >> m >> cl >> ce >> v;
    vector<ll> ve(ce), vl(cl);
    for (int i = 0; i < cl; ++i)
        cin >> vl[i];
    for (int i = 0; i < ce; ++i)
        cin >> ve[i];
    sort(vl.begin(), vl.end());
    sort(ve.begin(), ve.end());
    int q;
    cin >> q;
    while (q--){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2){
            cout << abs(y1 - y2) << '\n';
            continue;
        }
        ll path = INF;
        auto ite = lower_bound(ve.begin(), ve.end(), y1);
        auto itl = lower_bound(vl.begin(), vl.end(), y1);
        if (!ve.empty()){
            if (ite != ve.begin())
                path = min(path, abs(*(ite - 1) - y1) + abs(*(ite - 1) - y2) + (abs(x1 - x2) + v - 1) / v);
            if (ite != ve.end())
                path = min(path, abs(*(ite) - y1) + abs(*(ite) - y2) + (abs(x1 - x2) + v - 1) / v);
        }
        if (!vl.empty()){
            if (itl != vl.begin())
                path = min(path, abs(*(itl - 1) - y1) + abs(*(itl - 1) - y2) + abs(x1 - x2));
            if (itl != vl.end())
                path = min(path, abs(*(itl) - y1) + abs(*(itl) - y2) + abs(x1 - x2));
        }
        cout << path << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    solve();
    return 0;
}