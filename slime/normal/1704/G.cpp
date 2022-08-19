//Awwawa! Dis cold yis ratten buy Pikachu!
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define db double
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
using namespace std;
const int maxn = 200005;
int a[maxn], n, m;
ll b[maxn];
ll bdif[maxn];
int adif[maxn];

#define pl pair<ll, ll>
pl calc(int a, int b)
{
    if (b > a || b < 0) return mp(0, -1);
    ll lans = 1ll * b * (b + 1) / 2;
    ll rans = 1ll * b * (a + 1) - lans;
    return mp(lans, rans);
}
bool chkin(ll a, pl b) {
    return (a >= b.fi && a <= b.se);
}
vi work(int a, ll b, int counts) {
    // <= a, sum = b
    vi res;
    for (int i = a; i >= 1; i--) {
        if (chkin(b, calc(i - 1, counts))) continue;
        else b -= i, res.pb(i), counts -= 1;
    }
    return res;
}
int l[maxn], r[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cin >> m;
        for (int i = 1; i <= m; i++)
            cin >> b[i];
        for (int i = 1; i <= n - 1; i++) {
            adif[i] = a[i + 1] + a[i];
            if (i % 2) adif[i] *= -1;
        }
        for (int i = 1; i <= n - 2; i++) 
            adif[i] = adif[i + 1] - adif[i];
        for (int i = 1; i <= n; i++) {
            if (i & 1) l[i] = adif[i], r[i] = adif[i] + 1;
            else l[i] = adif[i] - 1, r[i] = adif[i];
        }

        for (int j = 1; j < m; j++) {
            bdif[j] = b[j] + b[j + 1];
            if (j & 1)
                bdif[j] *= -1;
        }
        for (int j = 1; j <= m - 2; j++)
            bdif[j] = bdif[j + 1] - bdif[j];
        int flag = 0;

        vi res;
        for (int i = 1; i <= m - 2; i++)
            if (abs(bdif[i]) > 1e9)
                goto l1;
        for (int i = n; i >= 1; i--) {
            int len = n - i + 1;
            if (len < m) continue;
            int flag1 = 1;
            int flag2 = 0;
            int bestv = -1;
            {
                ll need = (b[1] + b[2]) - (a[i] + a[i + 1]);
                if (i % 2)
                    need *= -1;
                ll needa = b[1] - a[i];
                // odds - even = need
                ll to = i + 1;
                ll evens = to / 2, odds = to - evens;
                if (odds < need)
                    continue;
                int md = (odds - need) / 2;
                for (int ev = md - 3; ev <= md + 3; ev++)
                {
                    int ne = ev, nod = ev + need;
                    if (ne < 0 || ne > evens || nod < 0 || nod > odds)
                        continue;
                    ll needsum = needa;
                    if (i & 1)
                        needsum *= -1;
                    needsum -= (i + 1) * (ne - nod);
                    needsum *= -1; // (-1)^j * j

                    pl esum = calc(evens, ne);
                    esum.fi *= 2, esum.se *= 2;
                    pl osum = calc(odds, nod);
                    osum.fi *= 2, osum.se *= 2;
                    osum.fi -= nod, osum.se -= nod;

                    ll cdif = esum.fi - osum.fi;
                    if ((cdif - needsum) % 2)
                        continue;
                    if (needsum > esum.se - osum.fi)
                        continue;
                    if (needsum < esum.fi - osum.se)
                        continue;
                    bestv = ev;
                    flag2 = 1;
                    break;
                }
            }
            if (!flag2) continue;
            for (int j = 1; j <= m - 2; j++) {
                ll tochk = bdif[j];
                if (i % 2 == 0) tochk *= -1;
                if (tochk >= l[i + j - 1] && tochk <= r[i + j - 1]) continue;
                else {
                    flag1 = 0;
                    break;
                }
            }
            if (!flag1) continue;
            ll need = (b[1] + b[2]) - (a[i] + a[i + 1]); 
            if (i % 2) need *= -1;
            ll needa = b[1] - a[i];
            // odds - even = need
            ll to = i + 1;
            ll evens = to / 2, odds = to - evens;
            if (odds < need) continue;
            int md = (odds - need) / 2;
            for (int ev = bestv; ev <= bestv; ev++) {
                int ne = ev, nod = ev + need;
                if (ne < 0 || ne > evens || nod < 0 || nod > odds) continue;
                ll needsum = needa;
                if (i & 1) needsum *= -1;
                needsum -= (i + 1) * (ne - nod);
                needsum *= -1; // (-1)^j * j

                pl esum = calc(evens, ne); 
                esum.fi *= 2, esum.se *= 2;
                pl osum = calc(odds, nod); 
                osum.fi *= 2, osum.se *= 2; osum.fi -= nod, osum.se -= nod;

                ll cdif = esum.fi - osum.fi;
                if ((cdif - needsum) % 2) continue;
                if (needsum > esum.se - osum.fi) continue;
                if (needsum < esum.fi - osum.se) continue;
                ll st = osum.fi;
                if (st + needsum < esum.fi)
                    st = esum.fi - needsum;
                vi cr1 = work(evens, (st + needsum) / 2, ne);
                for (auto v : cr1)
                    res.pb(2 * v);
                vi cr2 = work(odds, (st + nod) / 2, nod);
                for (auto v : cr2)
                    res.pb(2 * v - 1);
                break;
            }
            for (int u = 1; u <= m - 2; u++)
                if ((bdif[u] - adif[u + i - 1]) % 2) 
                    res.pb(u + i + 1);
            flag = 1;
            break;
        }
        l1: ;
        if (!flag) {cout << -1 << "\n";}
        else {
            printf("%d\n", res.size());
            for (auto v : res)
                printf("%d ", v);
            printf("\n");
        }
    }
    return (0-0); //<3
}