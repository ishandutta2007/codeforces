//Awwawa! Dis cold yis ratten buy Pikachu!
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn =500005;
int a[maxn];
int t;
int mn = 1e9;
void work(int l, int r) {
    vector<pi> cur;
    for (int i = l; i <= r; i++)
        cur.pb(mp(a[i], i));
    sort(cur.begin(), cur.end());
    for (int i = 0; i < cur.size(); ) {
        int j = i;
        while (j < cur.size() && cur[j].fi == cur[i].fi) j += 1;
        vi cc;
        cc.pb(l - 1);
        cc.pb(r + 1);
        for (int k = i; k < j; k++)
            cc.pb(cur[k].se);
        int ca = 0;
        for (int i = 0; i < cc.size() - 1; i++) {
            ca += (cc[i + 1] - cc[i]) / 2;
        }
        chkmin(mn, ca);
        i = j;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        mn = 1e9;
        cin >> n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int f = n + 1, e = 0;
        for (int i = 1; i < n; i++)
            if (a[i] == a[i + 1]) chkmin(f, i), chkmax(e, i);
        int nans = 0;
        if (f <= n) nans = max(0, e - f - 1) ;
        if (e > f) chkmax(nans, 1);
        cout << nans << endl;
    }
    return (0-0); //<3
}