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

const int N = 1000001;
ll a[N];

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    ll s = 0;
    rep(i, n) {
        cin >> a[i];
        s += a[i];
    }
    if (s == 1) {
        cout << -1;
        return 0;
    }
    vector<ll> li;
    ll ans = 2e18, cs = s;
    for (ll i = 2; i * i <= cs; i++)
        if (cs % i == 0) {
            li.push_back(i);
            while (cs % i == 0)
                cs /= i;
        }
    if (cs > 1)
        li.push_back(cs);
    for (ll i : li) {
        ll ts = 0, ca = 0, x, s1 = 0, s2 = 0, cm;
        rep(j, n) {
            x = a[j];
            rep(z, 2) {
                cm = max(0ll, min(i / 2 - ts, x));
                x -= cm;
                s1 += cm * j;
                ts += cm;
                if (x && i == ts * 2 + 1) {
                    x--;
                    ts++;
                }
                cm = max(0ll, min(i - ts, x));
                x -= cm;
                s2 += cm * j;
                ts += cm;
                if (ts == i) {
                    ca += s2 - s1;
                    ts = 0;
                    s1 = 0;
                    s2 = 0;
                }
                x %= i;
            }
        }
        ans = min(ans, ca);
    }
    cout << ans;
}