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
int n, k;
int main() {
    cin >> n >> k;
    if ((k % 2 == 0) && (n % 2 == 1)) {
        cout << -1 << endl;
        return 0;
    }
    int tot = n;
    for (int i = 1; i <= n; i++) a[i] = 1;
    int pl = 1;
    if (tot % k != 0)
        while (1) {
            a[pl] += 2;
            tot += 2;
            if (tot % k == 0 && tot / k >= a[1]) break;
            pl++;
            if (pl == n + 1) pl = 1;
        }
    int ans = 0;
    for (int i = 1; i <= tot / k; i++) {
        vector<pi> hs;
        for (int j = 1; j <= n; j++)
            hs.pb(mp(a[j], j));
        sort(hs.begin(), hs.end());
        reverse(hs.begin(), hs.end());
        cout << "? ";
        for (int j = 0; j < k; j++)
            printf("%d ", hs[j].se), 
            a[hs[j].se]--;
        cout << endl;
        fflush(stdout);
        int res;
        scanf("%d", &res);
        ans ^= res;
    }
    cout << "! " << ans << endl;
    fflush(stdout);
    return 0;
}