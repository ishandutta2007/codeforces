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
const int maxn = 100005;
const int S = 405;
const int pls = maxn * S;
int mx[maxn * S * 2 + 10 * maxn];
int n;
int a[maxn];
int res;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int j = -S; j <= S; j++) {
        for (int k = 1; k <= n; k++) {
            int ed = a[k] + pls + k * j;
            mx[ed] += 1;
            chkmax(res, mx[ed]);
        }
        for (int k = 1; k <= n; k++) {
            int ed = a[k] + pls + k * j;
            mx[ed] = 0;
        }
    }
    chkmax(res, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= i + S && j <= n; j++) {
            int ee = (a[j] - a[i]);
            int cur = ee / (j - i) + pls;
            if (ee % (j - i)) continue;
            else mx[cur] += 1, chkmax(res, mx[cur] + 1);
        }
        for (int j = i + 1; j <= i + S && j <= n; j++) {
            int ee = (a[j] - a[i]);
            int cur = ee / (j - i) + pls;
            if (ee % (j - i)) continue;
            else mx[cur] = 0;
        }
    }
    cout << n - res << endl;
    return (0-0); //<3
}