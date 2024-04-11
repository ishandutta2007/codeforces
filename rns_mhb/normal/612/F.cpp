#include <bits/stdc++.h>
using namespace std;

#define N 2005

const int INF = 1e9;
template<class T> void chkmin(T &a, T b) { if (a > b) a = b; }

int n, s, m;
int a[N];
int z[N], id[N];
int dp[2][N], f[2][N];
int nxt[N], prv[N];
int ans;
vector<int> v[N];
int cnt;
int pos[N];

bool cmp(int x, int y) { return a[x] > a[y]; }
int dist(int x, int y) {
    if (x > y) swap(x, y);
    return min(y - x, n - y + x);
}
int cdist(int x, int y) {
    if (y <= x) return x - y;
    return n - y + x;
}

void calc_dp() {
    for (int x = m - 1; x >= 0; x --) {
        for (int ii = 0; ii < v[x].size(); ii ++) {
            int i = v[x][ii];
            if (a[i] == m - 1) dp[1][i] = 0;
            else {
                dp[1][i] = INF;
                for (int j = 0; j < n; j ++) {
                    if (a[j] == a[i] + 1) {
                        if (dp[1][i] > dp[0][j] + dist(i, j)) {
                            dp[1][i] = dp[0][j] + dist(i, j);
                            f[1][i] = j;
                        }
                    }
                }
            }
        }
        for (int ii = 0; ii < v[x].size(); ii ++) {
            int i = v[x][ii];
            if (v[x].size() == 1) dp[0][i] = dp[1][i], f[0][i] = i;
            else {
                dp[0][i] = dp[1][prv[i]] + cdist(prv[i], i), f[0][i] = 0;
                if (dp[0][i] > dp[1][nxt[i]] + cdist(i, nxt[i])) {
                    dp[0][i] = dp[1][nxt[i]] + cdist(i, nxt[i]);
                    f[0][i] = 1;
                }
            }
        }
    }
    ans = INF;
    int t = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] == 0) {
            if (ans > dp[0][i] + dist(i, s)) {
                ans = dp[0][i] + dist(i, s);
                t = i;
            }
        }
    }
    printf("%d\n", ans);
    if (cdist(s, t) == dist(s, t)) {
        printf("-%d\n", dist(s, t));
    }
    else printf("+%d\n", dist(s, t));
    int e = 0;
    while (1) {
        if (e == 0) {
            if (prv[t] == t) ;
            else {
                if (f[e][t] == 0) {
                    int tl = t, tr = nxt[t];
                    while (tr != t) {
                        printf("+%d\n", cdist(tr, tl));
                        tr = nxt[tr], tl = nxt[tl];
                    }
                    t = prv[t];
                }
                else {
                    int tl = prv[t], tr = t;
                    while (tl != t) {
                        printf("-%d\n", cdist(tr, tl));
                        tr = prv[tr], tl = prv[tl];
                    }
                    t = nxt[t];
                }
            }
        }
        else {
            if (a[t] == m - 1) break;
            else {
                if (cdist(t, f[e][t]) == dist(t, f[e][t])) {
                    printf("-%d\n", dist(t, f[e][t]));
                }
                else printf("+%d\n", dist(t, f[e][t]));
                t = f[e][t];
            }
        }
        e ^= 1;
    }
}

int main() {
    scanf("%d %d", &n, &s);
    s --;
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
        z[m++] = a[i];
        id[i] = i;
    }
    sort(z, z + m);
    m = unique(z, z + m) - z;
    for (int i = 0; i < n; i ++) {
        a[i] = lower_bound(z, z + m, a[i]) - z;
        v[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i ++) {
        if (v[a[i]].size() == 1) nxt[i] = prv[i] = i;
        else {
            for (int j = 1; j < n; j ++) {
                if (a[(i+j)%n] == a[i]) prv[i] = (i+j)%n;
                if (a[(i+n-j)%n] == a[i]) nxt[i] = (i+n-j)%n;
            }
        }
    }
    sort(id, id + n, cmp);
    calc_dp();
    return 0;
}