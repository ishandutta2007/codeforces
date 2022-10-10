#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXN = 1e5 + 10;
const ll INF = 1e18;
ll dp[21][MAXN], a[MAXN], cnt[MAXN], cost;
int curL, curR;
 
void solve(int k, int L, int R, int optL, int optR) {
    if(L > R || optL > optR)
        return;
    int mi = (L + R)/2, iniL = curL, iniR = curR;
    while(curL < optR + 1) {
        cnt[a[curL]]--;
        cost -= cnt[a[curL]];
        curL++;
    }
    while(curL > optR + 1) {
        curL--;
        cost += cnt[a[curL]];
        cnt[a[curL]]++;
    }
    while(curR < mi) {
        curR++;
        cost += cnt[a[curR]];
        cnt[a[curR]]++;
    }
    while(curR > mi) {
        cnt[a[curR]]--;
        cost -= cnt[a[curR]];
        curR--;
    }
    int opt = -1;
    ll ans = INF;
    for(curL = optR; curL >= optL; curL--) {
        cost += cnt[a[curL]];
        cnt[a[curL]]++;
        if(curL <= mi && dp[k - 1][curL - 1] + cost < ans) {
            ans = dp[k - 1][curL - 1] + cost;
            opt = curL;
        }
    }
    dp[k][mi] = ans;
    curL = optL;
    while(curL < opt) {
        cnt[a[curL]]--;
        cost -= cnt[a[curL]];
        curL++;
    }
    solve(k, L, mi - 1, optL, opt);
    solve(k, mi + 1, R, opt, optR);
    while(curL < iniL) {
        cnt[a[curL]]--;
        cost -= cnt[a[curL]];
        curL++;
    }
    while(curL > iniL) {
        curL--;
        cost += cnt[a[curL]];
        cnt[a[curL]]++;
    }
    while(curR < iniR) {
        curR++;
        cost += cnt[a[curR]];
        cnt[a[curR]]++;
    }
    while(curR > iniR) {
        cnt[a[curR]]--;
        cost -= cnt[a[curR]];
        curR--;
    }
}
 
int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= k; j++)
            dp[j][i] = INF;
    dp[0][0] = 0;
    for(int j = 1; j <= k; j++) {
        memset(cnt, 0, sizeof 0);
        cost = 0;
        curL = 1;
        curR = 0;
        solve(j, j, n, 1, n);
        /*for(int i = 0; i <= n; i++)
            cout << dp[j][i] << " ";
        cout << endl;*/
    }
    cout << dp[k][n] << '\n';
}