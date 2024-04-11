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
const int maxn = 200005;
int fa[maxn], sz[maxn];
int gfa(int a) {
    if (fa[a] == a) return a;
    return fa[a] = gfa(fa[a]);
}
int x[maxn], y[maxn];
int main() {
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        fa[i] = i, sz[i] = 1;
    for (int i = 1; i <= d; i++)
        scanf("%d%d", &x[i], &y[i]);
    int cnt = 1;
    for (int i = 1; i <= d; i++) {
        int xf = gfa(x[i]), yf = gfa(y[i]);
        if (xf == yf) cnt += 1;
        else fa[xf] = yf, sz[yf] += sz[xf];
        vi cur;
        for (int j = 1; j <= n; j++)
            if (fa[j] == j) 
                cur.pb(sz[j]);
        sort(cur.begin(), cur.end());
        reverse(cur.begin(), cur.end());
        int na = 0;
        for (int i = 0; i < cur.size() && i < cnt; i++)
            na += cur[i];
        na -= 1;
        printf("%d\n", na);
    }
    return (0-0); //<3
}