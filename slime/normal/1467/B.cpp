#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define maxn 500005
#define mod 998244353
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
int a[maxn];
int tp[maxn];
int chk(int u, int v, int w) {
    if (v < u && v < w) return 1;
    if (v > u && v > w) return 1;
    return 0;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i <= n + 3; i++) a[i] = 0, tp[i] = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        tp[n] = 0;
        a[n + 1] = 0;
        int sum = 0;
        for (int i = 2; i < n; i++) {
            tp[i] = 0;
            if (a[i] < a[i - 1] && a[i] < a[i + 1]) tp[i] = -1;
            else if (a[i] > a[i - 1] && a[i] > a[i + 1]) tp[i] = 1;
            sum += abs(tp[i]);
        }
        int ans = sum;
        for (int i = 2; i < n; i++) {
            int dc = abs(tp[i]) + abs(tp[i + 1]) + abs(tp[i - 1]);
            if (i > 2 && i < n - 1) {
                if (chk(a[i - 1], a[i + 1], a[i + 2]) && chk(a[i - 2], a[i - 1], a[i + 1]))
                    dc -= 1;
            }
            chkmin(ans, sum - dc);
        }
        cout << ans << endl;
        
    }
    return 0;
}
//can't first x the