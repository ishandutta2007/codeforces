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
ll mx[maxn][20];
ll mn[maxn][20];
int mb[maxn];
ll qmx(int l, int r) {
    int len = r - l + 1;
    int j = mb[len];
    return max(mx[l][j], mx[r - (1 << j) + 1][j]);
}
ll qmn(int l, int r) {
    int len = r - l + 1;
    int j = mb[len];
    return min(mn[l][j], mn[r - (1 << j) + 1][j]);
}
int a[maxn];
int b[maxn];
ll s[maxn];
int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        a[i] -= b[i];
        s[i] = s[i - 1] + a[i];
    } 
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < 20; j++)
            if ((1 << j) <= i) mb[i] = j;
    
    for (int i = 0; i < 20; i++)
        for (int j = 1; j <= n - (1 << i) + 1; j++) {
            if (i == 0) mx[j][i] = s[j];
            else {
                mx[j][i] = max(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]);
            }
        }
    
    for (int i = 0; i < 20; i++)
        for (int j = 1; j <= n - (1 << i) + 1; j++) {
            if (i == 0) mn[j][i] = s[j];
            else {
                mn[j][i] = min(mn[j][i - 1], mn[j + (1 << (i - 1))][i - 1]);
            }
        }
    for (int i = 1; i <= q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        ll ans = -(qmn(l, r) - s[l - 1]);
        if (s[r] != s[l - 1]) ans = -1;
        if (qmx(l, r) > s[l - 1]) ans = -1;
        printf("%lld\n", ans);
    }
    return (0-0); //<3
}