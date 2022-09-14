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
#include <ext/pb_ds/assoc_container.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 1 << 21;
int a[N];
vector<int> r;
ll s;
int h, g;

int f(int v) {
    if (!a[v])
        return 0;
    if (a[v * 2] > a[v * 2 + 1])
        return f(v * 2) + 1;
    return f(v * 2 + 1) + 1;
}

void d(int v) {
    if (!a[v * 2] && !a[v * 2 + 1]) {
        a[v] = 0;
    }
    else if (a[v * 2] > a[v * 2 + 1]) {
        a[v] = a[v * 2];
        d(v * 2);
    }
    else {
        a[v] = a[v * 2 + 1];
        d(v * 2 + 1);
    }
}

void go(int v, int ch) {
    if (ch >= g)
        return;
    while (ch + f(v) > g) {
        s -= a[v];
        r.push_back(v);
        d(v);
    }
    go(v * 2, ch + 1);
    go(v * 2 + 1, ch + 1);
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
    cin >> t;
    rep(z, t) {
        cin >> h >> g;
        s = 0;
        rep(i, 1 << (h + 1))
            a[i] = 0;
        for (int i = 1; i < (1 << h); i++) {
            cin >> a[i];
            s += a[i];
        }
        r.clear();
        go(1, 0);
        cout << s << '\n';
        for (int i : r)
            cout << i << ' ';
        cout << '\n';
    }
}