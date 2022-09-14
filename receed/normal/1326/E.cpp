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

const int N = 1 << 19;
int a[N], q[N], ans[N];
int tr[N * 2], mod[N * 2];

void push(int v) {
    tr[v] += mod[v];
    if (v < N) {
        mod[v * 2] += mod[v];
        mod[v * 2 + 1] += mod[v];
    }
    mod[v] = 0;
}

void rel(int v) {
    tr[v] = min(tr[v * 2], tr[v * 2 + 1]);
}

void add(int cl, int cr, int d, int v=1, int l=0, int r=N) {
    if (cr <= l || r <= cl) {
        push(v);
        return;
    }
    if (cl <= l && r <= cr) {
        mod[v] += d;
        push(v);
        return;
    }
    push(v);
    add(cl, cr, d, v * 2, l, (l + r) / 2);
    add(cl, cr, d, v * 2 + 1, (l + r) / 2, r);
    rel(v);
}

int main() {
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, x;
    cin >> n;
    rep(i, n) {
        cin >> x;
        a[x - 1] = i;
    }
    rep(i, n) {
        cin >> q[i];
        q[i]--;
    }
    int mp = 0;
    for (int i = n - 1; i >= 0; i--) {
        add(0, a[i] + 1, -1);
        while (tr[1] < 0) {
            ans[mp] = i;
            add(0, q[mp] + 1, 1);
            mp++;
        }
    }
    rep(i, n)
        cout << ans[i] + 1 << ' ';
}