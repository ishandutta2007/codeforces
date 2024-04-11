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
const ll MAXN = 507;
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
    ll n;
    cin >> n;
    ll now = 0;
    vector <ll> res(n);
    for (ll i = 0; i < n / 2; i++) {
        ll x;
        cin >> x;
        res[2 * i + 1] = x;
        ll nxt = -1;
        for (ll t = MAXN; t > 0; t--) {
            if (x % t) continue;
            ll y = (x / t) - t;
            if (y <= 0 || y % 2) continue;
            y /= 2;
            if (y <= now) continue;
            if (nxt == -1 || nxt > t + y) {
                res[2 * i] = y * y - now * now;
                nxt = t + y;
            }
        }
        if (nxt == -1) {
            cout << "No\n";
            return 0;
        }
        now = nxt;
        //cout << nxt << "\n";
    }
    cout << "Yes\n";
    for (ll i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
}