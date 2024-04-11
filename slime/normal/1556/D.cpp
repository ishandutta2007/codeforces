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
const int maxn = 10005;
vi r[maxn], g;
vi ask(int u, int v) {
    cout << "and " << u << ' ' << v << endl; fflush(stdout);
    int res; scanf("%d", &res);
    int ed; 
    cout << "or " << u << ' ' << v << endl; fflush(stdout);
    scanf("%d", &ed);
    vi ff(30);
    for (int i = 0; i < 30; i++) {
        int u = (res >> i) & 1, v = (ed >> i) & 1;
        ff[i] = u + v;
    }
    return ff;
}
int a[maxn];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 2; i <= n; i++)
        r[i] = ask(1, i);
    g = ask(2, 3);
    for (int i = 0; i < 30; i++) {
        int fx = (r[2][i] + r[3][i] - g[i]) / 2;
        a[1] += (fx) << i;
        for (int j = 2; j <= n; j++) {
            a[j] += (r[j][i] - fx) << i;
        }
    }
    sort(a + 1, a + n + 1);
    cout << "finish " << a[k] << endl; fflush(stdout);
    return (0-0); //<3
}