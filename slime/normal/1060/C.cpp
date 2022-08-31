#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define maxn 2005
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
ll md[2][maxn];
int a[2][maxn];

int main()
{
    int n[2];
    cin >> n[0] >> n[1];
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n[i]; j++)
            cin >> a[i][j];
        for (int k = 1; k <= n[i]; k++)
            md[i][k] = 3e9;
        for (int j = 1; j <= n[i]; j++) {
            ll cs = 0;
            for (int l = j; l <= n[i]; l++) {
                cs += a[i][l];
                chkmin(md[i][l - j + 1], cs);
            }
        }
    }
    ll x; cin >> x;
    ll ma = 0;
    for (int i = 1; i <= n[0]; i++)
        for (int j = 1; j <= n[1]; j++) {
            if (md[0][i] > x || md[1][j] > x) continue;
            if (md[0][i] * md[1][j] <= x) 
                chkmax(ma, 1ll * i * j);
        }
    cout << ma << endl;
    return 0;
}