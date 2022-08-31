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
const int maxn = 100005;
int a[maxn];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        ll x1 = 0, sum = 0;
        for (int i = 2; i < n; i++) {
            sum += a[i];
            x1 += (a[i] % 2);
        }
        if ((x1 == sum) || (n == 3 && (a[2] % 2))) {
            printf("-1\n");
        }
        else {
            sum += x1;
            printf("%lld\n", sum / 2);
        }
    }
    return (0-0); //<3
}