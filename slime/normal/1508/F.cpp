#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;

const int maxn = 25005;
int p[maxn];
int to[maxn];
int mx[maxn], mn[maxn]; //  / 

int flmx[maxn], flmn[maxn];
const int Q = 100005;
int l[Q], r[Q];
int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        to[i] = i;
        scanf("%d", &p[i]);
        mx[i] = mn[i] = i, flmx[i] = flmn[i] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        int pl = l - 1;
        for (int j = r; j >= l; j--) {
            if (to[j] <= l) {
                pl = j;
                break;
            }
        }
        for (int j = pl + 1; j <= r; j++) {
            ans -= flmn[j], ans -= flmx[j];
            for (int s = to[j] - 1; s >= l; s--) {
                if (p[s] < p[j] && (mn[j] == j || p[s] > p[mn[j]])) mn[j] = s, flmn[j] = 1;
                if (p[s] > p[j] && (mx[j] == j || p[s] < p[mx[j]])) mx[j] = s, flmx[j] = 1;
            }
            ans += flmn[j], ans += flmx[j];
            int u = mn[j], v = mx[j];
            if (u != j && v != j) {
                if (u < v && mn[v] == u && flmn[v]) flmn[v] = 0, ans--;
                if (v < u && mx[u] == v && flmx[u]) flmx[u] = 0, ans--; 
            }
            to[j] = l;
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
8 2
3 7 4 8 1 5 2 6
3 6
1 6
3 8
1 8
*/