//hey alc
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
const int maxn = 200005;
int a[maxn];
ll sum[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
        ll cur = 0;
        for (int i = 1; i <= n; i++)
            chkmax(cur, sum[i] - sum[max(0, i - k)]);
        k -= 1;
        ll ee = 0;
        if (k <= n)
            ee = 1ll * k * (k + 1) / 2;
        else {
            ee = 1ll * k * n;
            ee -= 1ll * (n - 1) * n / 2;
        }
        cur += ee;
        cout << cur << endl;
    }
    return (0-0); //<3
}