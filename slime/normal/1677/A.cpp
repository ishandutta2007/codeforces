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
const int maxn = 5005;
int p[maxn];
int cnt[maxn];
int main() {    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &p[i]);
        ll ans = 0;
        for (int b = 1; b <= n; b++) {
            memset(cnt, 0, sizeof(cnt));
            for (int j = 1; j < b; j++)
                cnt[p[j]] += 1;
            for (int j = 1; j <= n; j++)
                cnt[j] += cnt[j - 1];
            int tt = 0;
            for (int c = n; c > b; c--) {
                ans += tt * cnt[p[c]];
                if (p[c] < p[b]) tt += 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}