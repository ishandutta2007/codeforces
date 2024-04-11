//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<ll>
#define pi pair<int, int>
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 4005;
int t;
char s[maxn][maxn];

int fa[maxn], col[maxn];
int gfa(int a) {
    if (fa[a] == a) return a;
    return fa[a] = gfa(fa[a]);
}
void lk(int a, int b) {
    if (gfa(a) == gfa(b)) return ;
    int af = gfa(a), bf = gfa(b);
    fa[af] = bf; col[bf] ^= col[af];
}
int deg[maxn];
int tt[maxn];
vector<pi> eg;
int main() {
    int r, c;
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= c; j++) {
            if (s[i][j] == '1') deg[i] ^= 1, deg[j + r] ^= 1;
            else if (s[i][j] == '?') eg.pb(mp(i, j + r)), tt[i] += 1, tt[j + r] += 1;
        }
    }  
    int tot = 0;
    int id = r + c;
    for (int sum = 0; sum < 2; sum++) {
        int ans = 1;
        for (int j = 1; j <= id; j++) fa[j] = j, col[j] = 0;
        if ((r % 2 == 0) && (c % 2 == 0)) 
            ans = ksm(2, eg.size());
        else {
            if (c % 2 == 0) {
                int te = eg.size();
                for (int j = 1; j <= c; j++)
                    if (tt[j + r] == 0 && deg[j + r] != sum) 
                        ans = 0;
                    else if (tt[j + r] == 0)
                        te += 1;
                te -= c;
                ans = 1ll * ans * ksm(2, max(0, te)) % mod;
            }
            else if (r % 2 == 0) {
                int te = eg.size();
                for (int j = 1; j <= r; j++)
                    if (tt[j] == 0 && deg[j] != sum) 
                        ans = 0;
                    else if (tt[j] == 0) te += 1;
                te -= r;
                ans = 1ll * ans * ksm(2, max(0, te)) % mod;
            }
            else {
                for (int j = 1; j <= id; j++)
                    col[j] = deg[j] ^ sum;
                for (auto v : eg) 
                    lk(v.fi, v.se);//, cout << "ADE" << v.fi << ' ' << v.se << endl;
                int te = eg.size() - id;
                for (int j = 1; j <= id; j++)
                    if (fa[j] == j) {
                        te += 1;
                        //cout << "??" << j << ' ' << col[j] << endl;
                        if (col[j]) ans = 0;
                    }
                te = max(te, 0);
                ans = 1ll * ans * ksm(2, te) % mod;
            }
        }
        tot = (tot + ans) % mod;
    }
    if (r % 2 == 0 && c % 2 == 0)
        tot = ksm(2, eg.size());
    cout << tot << endl;
    return (0-0); //<3
}
/*
1

7
1 3 3 3 1 2 2
*/