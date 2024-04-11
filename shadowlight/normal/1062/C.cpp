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
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector <ll> pref(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        ll x = s[i] - '0';
        pref[i + 1] = x + pref[i];
    }
    vector <ll> sum(n + 1, 0), qt(n + 1, 0);
    sum[0] = 0, qt[0] = 1;
    for (ll i = 1; i <= n; i++) {
        sum[i] = (sum[i - 1] + qt[i - 1]) % INF;
        qt[i] = 2 * qt[i - 1] % INF;
    }
    for (ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        ll all = r - l + 1, cnt = pref[r] - pref[l - 1];
        ll now = (sum[cnt] + (qt[cnt] - 1 + INF) * (qt[all - cnt] - 1 + INF)) % INF;
        cout << now << "\n";
    }
}