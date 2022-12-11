#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef int ll;
const int N = 1e5 + 7;

int mn[19][N], mx[19][N];
ll n, s, l;
ll a[N], st[N], ans[N], mans[N], ta;
int t[N * 5];

int getd(int l, int r) {
    int d = st[r - l];
    return max(mx[d][l], mx[d][r - (1 << d)]) - min(mn[d][l], mn[d][r - (1 << d)]);
}

void ins(int v, int l, int r, int p, int x) {
    if (l + 1 == r) {
        t[v] = x;
        return;
    }
    int m = (l + r) / 2;
    if (p < m) ins(v * 2 + 1, l, m, p, x);
    else ins(v * 2 + 2, m, r, p, x);
    t[v] = min(t[v * 2 + 1], t[2 * v + 2]);
}

int get(int v, int l, int r, int L, int R) {
    if (l >= R || L >= r) return N + 1;
    if (L <= l && r <= R) return t[v];
    int m = (l + r) / 2;
    return min(get(v * 2 + 1, l, m, L, R), get(v * 2 + 2, m, r, L, R));
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n >> s >> l;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn[0][i] = mx[0][i] = a[i];
    }

    for (int i = 0; i < N * 5; i++)
        t[i] = N;

    for (int i = 1; i < 18; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
        }
    }

    st[1] = 0;
    for (int i = 1; i < N; i++) {
        st[i] = st[i - 1];
        if ((1 << st[i]) * 2 <= i)
            st[i]++;
        //cerr << i << " " << st[i] << "\n";
    }

    int L, R, M;
    for (int i = 0; i < n; i++) {
        L = 1;
        R = i + 2;
        while (R - L > 1) {
            M = (L + R) / 2;
            if (getd(i - M + 1, i + 1) <= s)
                L = M;
            else
                R = M;
        }
        if (L == i + 1) {
            if (i >= l - 1)
                ans[i] = 1;
            else
                ans[i] = N;
        } else {
            if (L < l)
                ans[i] = N;
            else
                ans[i] = get(0, 0, n, i - L, i - l + 1) + 1;
        }
        ins(0, 0, n, i, ans[i]);
    }

    if (ans[n - 1] >= N)
        cout << "-1\n";
    else
        cout << ans[n - 1];

    return 0;
}