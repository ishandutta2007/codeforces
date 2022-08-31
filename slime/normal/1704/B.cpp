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
#define maxn 200005
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
int n;
int a[maxn], x;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = 0;
        for (int i = 1; i <= n; ) {
            int j = i;
            int mx = a[i], mn = a[i];
            while (j + 1 <= n) {
                if (max(mx, a[j + 1]) - min(mn, a[j + 1]) <= 2 * x) {
                    j++;
                    mx = max(mx, a[j]);
                    mn = min(mn, a[j]);
                }
                else break;
            }
            ans += 1;
            i = j + 1;
        } 
        printf("%d\n", ans - 1);
    }
    return (0-0); //<3
}