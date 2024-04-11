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
const int maxn = 1000005;
char s[maxn], t[maxn];
char g[maxn];
vi cr[27];
int cnt[27];
int d[maxn];
int n;
int lb(int x) {
    return x & -x;
}
void ins(int pl, int x) {
    while (pl <= n) {
        d[pl] += x;
        pl += lb(pl);
    }
}
int q(int p) {
    int ans = 0;
    while (p) ans += d[p], p -= lb(p);
    return ans;
} 
int gg(int a) {
    if (cnt[a] >= cr[a].size()) return maxn + 10;
    int g = cr[a][cnt[a]];
    int res = q(n) - q(g) + g;
    return res;
}
int gpl(int a) {
    if (cnt[a] >= cr[a].size()) return maxn + 10;
    return cr[a][cnt[a]];
}
int main() {
    int q;
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            d[i] = 0;
        scanf("%s", s + 1);
        scanf("%s", t + 1);
        for (int i = 0; i < 26; i++)
            cr[i].clear();
        for (int i = 1; i <= n; i++)
            cr[s[i] - 'a'].pb(i), 
            g[i] = s[i];
        
        sort(g + 1, g + n + 1);
        int flag = 1, p = 0;
        for (int i = 1; i <= n; i++) {
            if (g[i] != t[i]) {
                p = i;
                break;
            }
        }
        if (!p || g[p] > t[p]) flag = 0;
        if (!flag) cout << -1 << endl;
        else {
            memset(cnt, 0, sizeof(cnt));
            ll ans = 0;
            ll rans = 1e18;
            for (int m = 1; m <= n; m++) {
                int cmn = maxn;
                int rr = t[m] - 'a';
                for (int j = 0; j < rr; j++)
                    chkmin(cmn, gg(j));
                if (cmn < maxn)
                    chkmin(rans, ans + max(0, cmn - m));
                int cur = gg(rr);
                if (cur >= maxn) break;
                else {
                    ins(gpl(rr), 1);
                    cnt[rr] += 1;
                    ans += max(0, cur - m);
                }
            }
            cout << rans << endl;
        }
    }
    return (0-0); //<3
}