// Awwawa! Dis cold yis ratten buy Pikachu!
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
        int n, z;
        int ans = 0;
        cin >> n >> z;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            chkmax(ans, a| z);
        }
        cout << ans << endl;
    }
    return (0-0); //<3
}