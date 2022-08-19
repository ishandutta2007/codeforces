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
const int maxn =200005;
int a[maxn];
int t;

int main() {
    int n;
    cin >> n;
    int ans = (2 * n - 1) / 3;
    if ((2 * n - 1) % 3) ans += 1;
    cout << ans << endl;
    int fl = 0;
    if (ans % 2 == 0) fl = 1, ans--;
    int k = ans / 2; 
    for (int i = 1; i <= k + 1; i++) {
        printf("%d %d\n", i, k + 2 - i);
    }
    for (int i = k + 2; i <= ans; i++)
        printf("%d %d\n", i, ans + k + 2 - i);
    if (fl) printf("%d %d\n", ans + 1, ans + 1);
    return (0-0); //<3
}