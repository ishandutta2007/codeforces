//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<ll, ll>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 2000005;
int a[maxn];
int n;
pi cal(int t) {
    ll ls = 1ll * t * t;
    ll rs = ls + t;
    return mp(ls, rs);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < maxn; i++) {
        int nt = i;
        pi cr = cal(nt); 
        cr.fi -= a[1], cr.se -= a[1];
        chkmax(cr.fi, 0ll);
        if (cr.fi > cr.se) continue;
        int pl = 1;
        while (cr.fi <= cr.se) {
            pi cc = cal(nt);
            ll nd = cc.se - cr.fi + 1; // if >= nd : bad
            int pp = lower_bound(a + 1, a + n + 1, nd) - a; 
            if (pp == n + 1) break;
            else {
                chkmin(cr.se, cc.se - a[pp - 1]);
                pl = pp;
                ll cc = a[pl] + cr.fi;
                while (cal(nt).se < cc) nt++;
                chkmax(cr.fi, cal(nt).fi - a[pl]);
            }
        }
        if (cr.fi <= cr.se) {
            cout << cr.fi << endl;
            return 0;
        }

    }
    return (0-0); //<3
}