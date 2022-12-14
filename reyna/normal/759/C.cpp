// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

const int N = (int) 1e6 + 6, mod = (int) 0;
int a[N], ch[N], mx[N];
void push(int v) {
    ch[v << 1 | 0] += ch[v];
    ch[v << 1 | 1] += ch[v];
    mx[v << 1 | 0] += ch[v];
    mx[v << 1 | 1] += ch[v];
    ch[v] = 0;
}
void update(int i, int j, int x, int v = 1, int b = 0, int e = 1e5 + 5) {
    if (i >= e || b >= j) return;
    if (i <= b && e <= j) {
        mx[v] += x;
        ch[v] += x;
        return;
    }
    int m = b + e >> 1, l = v << 1, r = l | 1;
    push(v);
    update(i, j, x, l, b, m);
    update(i, j, x, r, m, e);
    mx[v] = max(mx[l], mx[r]);
}

int query(int v = 1, int b = 0, int e = 1e5 + 5) {
    if (mx[v] <= 0) return -1;
    if (b + 1 == e) return b;
    int m = b + e >> 1, l = v << 1, r = l | 1;
    push(v);
    int ansl = query(r, m, e);
    if (ansl != -1) return ansl;
    return query(l, b, m);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(a, -1, sizeof a);
    int m;
    cin >> m;
    while (m--) {
        int p, t;
        cin >> p >> t;
        --p;
        if (t == 0) {
            update(0, p + 1, -1);
        } else {
            int x;
            cin >> x;
            a[p] = x;
            update(0, p + 1, 1);
        }
        int z = query();
        if (z == -1) cout << -1 << '\n';
        else cout << a[z] << '\n';
    }
}