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
const double INF = 1e9;
const double EPS = 1e-9;
const int MSIZE = 200000;

bool is_great(ll ei1, ll ej1, ll ek1, ll ei2, ll ej2, ll ek2){
    ll val1 = (ek1 - ej1) * (ek2 - ei2);
    ll val2 = (ek2 - ej2) * (ek1 - ei1);
    return val1 < val2;
}

void solve(){
    ll n, u;
    cin >> n >> u;
    vector<ll> e(n);
    for (int i = 0; i < n; ++i)
        cin >> e[i];
    ll i = -1, j, k;
    int r = 0;
    for (int z = 0; z < n; ++z){
        while(r + 1 < n && e[r + 1] - e[z] <= u)
            r++;
        if (r - z + 1 >= 3 && (i == -1 || is_great(e[i], e[j], e[k], e[z], e[z + 1], e[r])))
            i = z, j = z + 1, k = r;
    }
    if (i == -1)
        cout << -1;
    else {
        long double val = (long double)(e[k] - e[j]) / (e[k] - e[i]);
        cout << fixed << setprecision(9) << val << '\n';
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