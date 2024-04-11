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
int t[maxn];
int hv[maxn];
int ans[maxn];
vi cur[maxn];
void push(vi a) {
    for (int i = 0; i <a.size(); i++) {
        int x = a[i];
        int y = a[(i + 1) % a.size()];
        ans[x] = t[y];
    }
}
int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> t[i];
        for (int i = 1; i <= n; i++) cur[i].clear();
        for (int i = 1; i <= n; i++) 
            cur[t[i]].pb(i);
        vector<pi> ss;
        for (int i = 1; i <= n; i++) 
            ss.pb(mp((int)cur[i].size(), i));
        sort(ss.begin(), ss.end());
        reverse(ss.begin(), ss.end());
        for (int i = 0; i < ss[0].fi; i++) {
            vi tt;
            for (int j = 0; j < ss.size(); j++) {
                if (ss[j].fi > i) tt.pb(cur[ss[j].se][i]);
                else break;
            }
            push(tt);
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    }
    return (0-0); //<3
}
/*
1
4
1 2 3 -4
*/