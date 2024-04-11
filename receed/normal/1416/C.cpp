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

const int N = 310000 * 31;
ll g[N][2], c[N], sz;
ll c1[30], c0[30];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, x, v;
    cin >> n;
    rep(i, n) {
        cin >> x;
        v = 0;
        for (int j = 29; j >= 0; j--) {
            if (x & (1ll << j)) {
                c1[j] += c[g[v][0]];
                if (!g[v][1])
                    g[v][1] = ++sz;
                v = g[v][1];
            }
            else {
                c0[j] += c[g[v][1]];
                if (!g[v][0])
                    g[v][0] = ++sz;
                v = g[v][0];
            }
            c[v]++;
        }
    }
    ll ans = 0, res = 0;
    rep(j, 30) {
        if (c1[j] < c0[j]) {
            ans |= (1ll << j);
            res += c1[j];
        }
        else
            res += c0[j];
    }
    cout << res << ' ' << ans;
}