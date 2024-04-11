//Awwawa! Dis cold yis ratten buy Pikachu!
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
const int maxn = 100005;
int fa[maxn], col[maxn];
int gfa(int a) {
    if (fa[a] == a) return a;
    int cur = gfa(fa[a]);
    col[a] ^= col[fa[a]];
    fa[a] = cur;
    return cur;
}
int a[maxn], d[maxn];
int res;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) 
            fa[i] = i, col[i] = 0, d[i] = 0;
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            d[u] += 1, d[v] += 1;
            int uf = gfa(u), vf = gfa(v);
            fa[uf] = vf, col[uf] = col[u] ^ col[v] ^ 1;
        }
        for (int i = 1; i <= n; i++) {
            gfa(i);
            int res = d[i];
            if (col[i]) res *= -1;
            printf("%d ", res);
        }
        printf("\n");
    }
    return (0-0); //<3
}