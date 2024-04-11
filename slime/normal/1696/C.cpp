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
const int maxn = 500005;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        int h[2];
        cin >> h[0] >> m;
        vector<pair<int, ll> > s[2], nx[2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < h[i]; j++) {
                int cur;
                scanf("%d", &cur);
                int cnt = 1;
                while (cur % m == 0) {
                    cur /= m;
                    cnt *= m;
                }
                s[i].pb(mp(cur, cnt));
            }
            if (i == 0) cin >> h[1];
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < s[i].size(); ) {
                int k = j;
                ll tot = 0;
                while (k < s[i].size() && s[i][k].fi == s[i][j].fi)
                    tot += s[i][k].se, 
                    k++;
                nx[i].pb(mp(s[i][j].fi, tot));
                j = k;
            }
        }
        if (nx[0] == nx[1]) cout << "YES" << endl;
        else cout << "NO" << endl;
    } 
    return (0-0); //<3
}