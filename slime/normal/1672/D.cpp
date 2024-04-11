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
const int maxn = 200005;
int n;
int hv[maxn];
vi cal(vi x) {
    for (int i = 1; i <= n; i++) hv[i] = 0;
    vi res;
    for (auto v : x) {
        if (!hv[v]) res.pb(v);
        hv[v] = 1;
    }
    return res;
}
int nx[maxn];
int cnt[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vi a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
        for (int i = 1; i <= n; i++) cnt[i] = 1;
        for (int i = n; i >= 1; i--) 
            hv[i] = n + 1;
        for (int i = n; i >= 1; i--) {
            nx[i] = hv[a[i]];
            hv[a[i]] = i;
        }
        int nid = 1;
        int flag = 1;
        for (int i = 1; i <= n; i++) {
            while (nid <= n && a[nid] != b[i]) {
                if (nx[nid] > n) flag = 0;
                cnt[nx[nid]] += cnt[nid];
                nid += 1;
            }
            cnt[nid] -= 1;
            if (cnt[nid] == 0) nid += 1;
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return (0-0); //<3
}