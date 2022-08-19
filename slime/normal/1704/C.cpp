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
const int maxn = 400005;
int work(vi a, int days) {
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int ans = 0;
    for (auto v : a) {
        int rem = v - 2 * days;
        if (rem >= 3) {
            days += 2;
            ans += rem - 1;
        }
        else if (rem <= 2 && rem >= 1) {
            days += 1;
            ans += 1;
        }
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vi cur(m);
        for (int i = 0; i < m; i++)
            cin >> cur[i];
        sort(cur.begin(), cur.end());
        int fr = cur[0] - 1, ed = n - cur[m - 1];
        vi mid;
        for (int i = 0; i + 1 < m; i++) 
            mid.pb(cur[i + 1] - cur[i] - 1);
        mid.pb(fr + ed);
        int ans = work(mid, 0);
        printf("%d\n", n - ans);
        
    }
    return (0 - 0); 
}