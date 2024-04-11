//Awwawa! Dis cold yis ratten buy tEMMIE!
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
int a[maxn], b[maxn];
int n;
bool chk(int s) {
    vi u(n + s), v(n + s);
    for (int i = 0; i < n; i++)
        u[i] = a[i + 1], v[i] = b[i + 1];
    for (int i = n; i < n + s; i++)
        u[i] = 100, v[i] = 0;
    sort(u.begin(), u.end());
    sort(v.begin(), v.end());
    reverse(u.begin(), u.end());
    reverse(v.begin(), v.end());
    int res = (n + s) - (n + s) / 4;
    ll sum = 0;
    for (int i = 0; i < res; i++)
        sum += u[i] - v[i];
    if (sum >= 0) return 1;
    return 0;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        int l = 0, r = n;
        while (l < r) {
            int mid  = (l + r) / 2;
            if (chk(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}