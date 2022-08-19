//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 3
#define S 20
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 250005;
int a[maxn], b[maxn];
int n, q;
char s[maxn];
struct th {
    int u[maxn];
    int s[maxn], s1[maxn];
    void build() {  
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1];
            if (u[i]) s[i] += 1;
            else s[i] -= 1;
            s1[i] = s1[i - 1];
            if (u[i] == 0 && u[i - 1] == 0 && i >= 2) s1[i] += 1;
        }

    }
    int cal(int l, int r) {
        int gr = s[r] - s[l - 1];
        if (u[l] == 0) gr += 1;
        if (u[r] == 0) gr += 1;
        // r ~ l + 1
        gr += s1[r] - s1[l];
        return gr;
    }
}h[2];
int main() {
    cin >> n >> q;
    scanf("%s", s + 1);
    for (int i = 0; i < 2; i++) 
        for (int j = 1; j <= n; j++)
            h[i].u[j] = (s[j] == '0' + i);
    for (int i = 0; i < 2; i++)
        h[i].build();
    for (int i = 1; i <= q; i++) {
        int ans = 0;
        int l, r; scanf("%d%d", &l, &r);
        chkmax(ans, h[0].cal(l, r));
        chkmax(ans, h[1].cal(l, r));
        printf("%d\n", ans);
    }
    return (0-0); //<3
}
/*
1
4
1 2 3 -4
*/