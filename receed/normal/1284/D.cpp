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

const int N = 100001;
ll h[N], v[N], x[N];
mt19937 gen(228);
uniform_int_distribution<ll> dis(1, 1e18);

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
    cin >> n;
    rep(i, n)
        h[i] = dis(gen);
    vector<vector<vector<ll>>> a(2, vector<vector<ll>>(n, vector<ll>(3)));
    rep(i, n)
        rep(j, 2) {
            cin >> a[j][i][0] >> a[j][i][1];
            a[j][i][2] = i;
        }
    rep(z, 2) {
        sort(all(a[z]));
        x[n] = 0;
        for (int i = n - 1; i >= 0; i--)
            x[i] = x[i + 1] ^ h[a[z][i][2]];
        rep(i, n) {
            int pos = lower_bound(all(a[z]), vector<ll> {a[z][i][1] + 1, 0, 0}) - a[z].begin();
            v[a[z][i][2]] ^= x[pos];
        }
        rep(i, n)
            swap(a[z][i][0], a[z][i][1]);
        sort(all(a[z]));
        x[0] = 0;
        rep(i, n)
            x[i + 1] = x[i] ^ h[a[z][i][2]];
        rep(i, n) {
            int pos = lower_bound(all(a[z]), vector<ll> {a[z][i][1], 0, 0}) - a[z].begin();
            v[a[z][i][2]] ^= x[pos];
        }
    }
    int f = 0;
    rep(i, n) {
        if (v[i])
            f = 1;
    }
    if (f)
        cout << "NO";
    else
        cout << "YES";
}