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

struct pt {
    ll x, y;
    pt() : x(0), y(0) {}
    pt(ll x, ll y) : x(x), y(y) {}

    pt operator-(pt p) {
        return {x - p.x, y - p.y};
    }

    ll operator*(pt p) {
        return x * p.y - y * p.x;
    }
};

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
    cin >> n;
    vector<pt> a(n), b(n - 1);
    ll ans = n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
    rep(i, n)
        cin >> a[i].x >> a[i].y;
    rep(i, n) {
        pt p = a[i];
        int pos = 0;
        rep(j, n)
            if (j != i)
                b[pos++] = a[j] - a[i];
        sort(all(b), [](pt p1, pt p2) {
                if (p1.y >= 0 && p2.y < 0)
                    return true;
                if (p2.y >= 0 && p1.y < 0)
                    return false;
                return p1 * p2 > 0;
        });
        pos = 0;
        rep(i, n - 1) {
            while (1) {
                int np = (pos + 1) % (n - 1);
                if (np == i || b[i] * b[np] < 0)
                    break;
                pos = np;
            }
            ll cc = (pos - i + n - 1) % (n - 1) + 1;
            ans -= (cc - 1) * (cc - 2) * (cc - 3) / 6;
            if (cc == 1)
                pos = (pos + 1) % (n - 1);
        }
    }
    cout << ans;
}