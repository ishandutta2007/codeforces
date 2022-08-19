#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define maxn 300005
#define mod 1000000007
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b) {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
int tp[maxn];
int n;
int dp[maxn];

int k = 0;
vi eg[maxn];
int cur;
void dfs(int a) {
    for (auto v : eg[a]) {
        dfs(v);
    }
    if (eg[a].size() == 0) dp[a] = 1;
    else {
        if (tp[a] == 0) {
            dp[a] = 0;
            for (auto v : eg[a])    
                dp[a] += dp[v];
        }
        else {
            int mn = 1e9;
            for (auto v : eg[a])
                chkmin(mn, dp[v]);
            dp[a] = mn;
        }
    }
}
bool chk(int a) {
    cur = a;
    dfs(1);
    return dp[1] <= k - a + 1;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> tp[i];
    for (int i = 2; i <= n; i++) {
        int f;
        cin >> f;
        eg[f].pb(i);
    }
    for (int i = 1; i <= n; i++)
        if (eg[i].size() == 0) k += 1;
    int l = 1, r = k;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (chk(mid + 1)) l = mid + 1;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}