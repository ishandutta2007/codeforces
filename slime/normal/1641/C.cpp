//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
int tp[maxn], l[maxn], r[maxn], qs[maxn];
int res[maxn], t[maxn];
int fa[maxn];
int gfa(int x) {
    if (fa[x] == x) return x;
    return fa[x] = gfa(fa[x]);
}
int sum[maxn], mx[maxn][20], ls[maxn];
int qmx(int l, int r) {
    int len = r - l + 1;
    for (int i = 0; i < 20; i++) {
        if ((1 << (i + 1)) >= len) {
            int res = max(mx[l][i], mx[r - (1 << i) + 1][i]);
            return res;
        }
    }
}
int main() {
    int n, q;
    cin >> n >> q;
    memset(res, -1, sizeof(res));
    for (int i = 0; i < maxn; i++) 
        fa[i] = i;
    for (int i = 1; i <= q; i++) {
        scanf("%d", &qs[i]);
        if (qs[i] == 0)
            scanf("%d%d%d", &l[i], &r[i], &tp[i]);
        else scanf("%d", &l[i]);
    }
    for (int i = 1; i <= q; i++) 
        if (qs[i] == 0 && tp[i] == 0) {
            int p = gfa(l[i]);
            while (p <= r[i]) {
                res[p] = 0, t[p] = i, fa[p] = p + 1;
                p = gfa(p + 1);
            }
        }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (res[i] != 0);
        ls[i] = ls[i - 1];
        if (res[i] == -1) ls[i] = i;
    }
    for (int j = 0; j < 20; j++)
        for (int i = 1; i <= n; i++) {
            if (j == 0) mx[i][j] = t[i];
            else {
                mx[i][j] = mx[i][j - 1];
                if (i + (1 << (j - 1)) <= n)
                    chkmax(mx[i][j], mx[i + (1 << (j - 1))][j - 1]);
            }
        }
    for (int i = 1; i <= q; i++) {
        if (qs[i] == 0 && tp[i] == 1) {
            int s = sum[r[i]] - sum[l[i] - 1];
            if (s != 1) continue;
            else {
                int pl = ls[r[i]];
                int cur = qmx(l[i], r[i]);
                if (res[pl] == -1) res[pl] = 1, t[pl] = max(cur, i);
                else if (res[pl] == 1) chkmin(t[pl], max(cur, i));
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        if (qs[i] == 1) {
            int p = l[i];
            int re = res[p];
            if (t[p] >= i) re = -1;
            if (re == -1) printf("N/A\n");
            else if (re == 1) printf("YES\n");
            else printf("NO\n");
        }
    }
    
    return (0-0); //<3
}