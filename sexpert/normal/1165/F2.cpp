#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXN = 4e5 + 19;
int dp[MAXN], abv[MAXN], a[MAXN], used[MAXN];
vector<int> offers[MAXN];
 
int moff(int n) {
    memset(used, 0, sizeof used);
    memset(abv, 0, sizeof abv);
    for(int d = n; d >= 1; d--) {
        for(auto o : offers[d]) {
            if(used[o]) continue;
            abv[d] += a[o];
            used[o] = 1;
        }
    }
    dp[0] = 0;
    for(int d = 1; d <= n; d++)
        dp[d] = min(dp[d - 1] + abv[d], d);
    //cout << n << ": ";
    //for(int d = 0; d <= min(n, MAXN - 1); d++)
    //    cout << dp[d] << " ";
    //cout << '\n';
    return dp[n];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int pt = 1;
    for(int i = 1; i <= n; i++)
        pt += a[i];
    pt--;
    for(int i = 0; i < m; i++) {
        int d, t;
        cin >> d >> t;
        if(a[t] == 0) continue;
        offers[d].push_back(t);
    }
    //for(int i = 1; i <= 10; i++) {
    //    cout << i << ": ";
    //    for(auto o : offers[i])
    //        cout << o << " ";
    //    cout << '\n';
    //}
    int lo = 1, hi = 2*pt + 2;
    while(lo < hi) {
        int mi = (lo + hi)/2;
        int d = moff(mi);
        //cout << mi << " " << moff(mi) << endl;
        if(mi - d >= 2*(pt - d)) hi = mi;
        else lo = mi + 1;
    }
    cout << lo << endl;
}