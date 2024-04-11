#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define maxn 200005
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
int n;
int a[maxn];
int d[maxn];
int q[maxn];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], d[a[i]] += 1;
    int fr = 0, ed = 0;
    for (int i = 1; i <= n; i++)
        if (!d[i]) q[ed++] = i;
    while (fr < ed) {
        int cur = q[fr++];
        d[a[cur]] -= 1;
        if (d[a[cur]] == 0) q[ed++] = a[cur];
    }
    ll ans = ksm(2, n);
    for (int i = 1; i <= n; i++) {
        if (d[i]) {
            vi cur;
            int j = i;
            while (1) {
                cur.pb(j);
                j = a[j];
                if (j == i) break;
            }
            ll cr = ksm(2, cur.size()) - 2;
            ans = ans * cr % mod;
            ans = ans * ksm((mod + 1) / 2, cur.size()) % mod;
            for (auto v : cur)
                d[v] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}