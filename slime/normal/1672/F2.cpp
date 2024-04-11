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
int hv[maxn];
int ans[maxn];
vi cur[maxn];
vi to[maxn];
int cnt[maxn];
void del(int x) {
    if (!hv[x]) return ;
    hv[x] = 0; cnt[a[x]] -= 1;
    if (cnt[a[x]] == 0) 
        for (auto v : to[a[x]]) del(v);
}
int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cur[i].clear(), to[i].clear();
        for (int i = 1; i <= n; i++) 
            cur[a[i]].pb(i);
        for (int i = 1; i <= n; i++) 
            scanf("%d", &b[i]), 
            to[b[i]].pb(i);
        for (int i = 1; i <= n; i++) cnt[i] = cur[i].size(), hv[i] = 1;
        int mc = 0, id = 0;
        for (int i = 1; i <= n; i++)
            if (chkmax(mc, cnt[i])) id = i;
        for (auto v : cur[id]) del(v);
        int flag = 1;
        for (int i = 1; i <= n; i++)
            if (hv[i]) flag = 0;
        if (!flag) cout << "WA" << endl;
        else cout << "AC" << endl;
    }
    return (0-0); //<3
}
/*
1
4
1 2 3 -4
*/