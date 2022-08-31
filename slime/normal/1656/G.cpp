//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<ll>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
int t;

int n, a[maxn];
int fa[maxn], sp[maxn]; // sp : one of the pairs
int to[maxn];
int fr[maxn];
int gfa(int a) {
    if (fa[a] == a) return a;
    return fa[a] = gfa(fa[a]);
}
void lk(int a, int b) {
    int af = gfa(a), bf = gfa(b);
    if (af == bf) return ;
    fa[af] = bf;
    if (sp[af]) sp[bf] = sp[af];
}
void ass(int a, int b) {
    to[a] = b, fr[b] = a;
    lk(a, b);
}
void sw(int a, int b) {
   // cout << "SW" << a << ' ' << b << endl;
    swap(to[a], to[b]);
    swap(fr[to[a]], fr[to[b]]);
    lk(a, to[a]);
    lk(b, to[b]);
}
vi hh[maxn];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) {
            fa[i] = i; 
            sp[i] = 0, hh[i].clear();
        }
        vector<vi> tot, sing;
        for (int i = 1; i <= n; i++) 
            hh[a[i]].pb(i);
        for (int i = 1; i <= n; i++) {
            if (hh[i].size() % 2) 
                if (hh[i][hh[i].size() - 1] == (n + 1) / 2)
                    swap(hh[i][0], hh[i][hh[i].size() - 1]);

            for (int j = 0; j < hh[i].size(); j += 2) {
                vi cur;
                for (int k = j; k < hh[i].size() && k < j + 2; k++)
                    cur.pb(hh[i][k]);
                if (cur.size() == 1) sing.pb(cur);
                else tot.pb(cur);
            }
        }
        if (sing.size() > 1) {
            printf("NO\n");
            continue;
        }
        else if (sing.size() == 1) {
            int t = sing[0][0];
            if (t == (n + 1) / 2) {
                printf("NO\n");
                continue;
            }
        }
        for (int i = 1; i <= n; i++) 
            if (n % 2 == 0 || (n + 1) / 2 != i) 
                sp[i] = i;
        for (int i = 1; i <= n; i++) 
            if (n + 1 - i != i) lk(i, n + 1 - i);
        if (sing.size()) 
            ass(sing[0][0], (n + 1) / 2);
        for (int i = 0; i < tot.size(); i++) {
            ass(tot[i][0], i + 1);
            ass(tot[i][1], n - i);
        }
        vi hh;
        for (int i = 1; i <= n; i++) 
            if (gfa(i) == i) hh.pb(i);
        for (int i = 1; i < hh.size(); i++) {
            int cur = hh[i], f = hh[0];
            cur = sp[cur], f = sp[f];
            assert(cur && f);
            sw(fr[cur], fr[f]);
            sw(fr[n + 1 - cur], fr[n + 1 - f]);
        }
        for (int i = 1; i <= n; i++) 
            fa[i] = i;
        for (int i = 1; i <= n; i++)
            lk(i, to[i]);
        printf("YES\n");
        for (int i = 1; i <= n; i++) 
            if (gfa(i) != gfa(n + 1 - i))
                sw(fr[i], fr[n + 1 - i]);
        for (int i = 1; i <= n; i++)
            printf("%d ", fr[i]);
        printf("\n");
    }
    return (0-0); //<3
}
/*
1

7
1 3 3 3 1 2 2
*/