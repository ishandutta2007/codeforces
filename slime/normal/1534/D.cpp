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
vi ff;
vi ask(int a) {
    if (a == 1 && ff.size()) return ff;
    cout << "? " << a << endl;
    fflush(stdout);
    vi res(n + 1);
    for (int i = 1; i <= n; i++)
        scanf("%d", &res[i]);
    return res;
}
int main() {
    cin >> n;
    vi cr = ask(1);
    ff = cr;
    vi h[2];
    for (int i = 1; i <= n; i++)
        if (cr[i] & 1) h[1].pb(i);
        else h[0].pb(i);
    if (h[1].size() < h[0].size()) swap(h[0], h[1]);
    vector<pi> cur;
    for (auto v : h[0]) {
        vi gg = ask(v);
        for (int j = 1; j <= n; j++)
            if (gg[j] == 1) cur.pb(mp(v, j));
    }
    cout << "! " << endl;
    for (auto v : cur)
        cout << v.fi << ' ' << v.se << endl;
    fflush(stdout);
    return 0;
}