#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int INF = 1e8;
int memo[MAXN][5][5], cnt[MAXN], n, m;

int dp(int pos, int fs, int sd) {
    if(memo[pos][fs][sd] != -1)
        return memo[pos][fs][sd];
    if(cnt[pos] < fs)
        return memo[pos][fs][sd] = -INF;
    if(pos + 1 <= m && cnt[pos + 1] < sd)
        return memo[pos][fs][sd] = -INF;
    if(pos == m)
        return memo[pos][fs][sd] = (cnt[pos] - fs)/3;
    int ans = (cnt[pos] - fs)/3 + dp(pos + 1, sd, 0);
    //cout << pos << " " << fs << " " << sd << " " << ans << endl;
    if(pos + 2 <= m) {
        if(cnt[pos] - fs >= 1 && cnt[pos + 1] - sd >= 1 && cnt[pos + 2] >= 1)
            ans = max(ans, 1 + (cnt[pos] - fs - 1)/3 + dp(pos + 1, sd + 1, 1));
        if(cnt[pos] - fs >= 2 && cnt[pos + 1] - sd >= 2 && cnt[pos + 2] >= 2)
            ans = max(ans, 2 + (cnt[pos] - fs - 2)/3 + dp(pos + 1, sd + 2, 2));
    }
    //cout << pos << " " << fs << " " << sd << " " << ans << endl;
    return memo[pos][fs][sd] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    memset(memo, -1, sizeof memo);
    cout << dp(1, 0, 0) << endl;
}