#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll memo[105][105][105], best[105], cost[105];
vector<int> seg = {0};
int n;
 
ll dp(int i, int j, int off) {
    if(memo[i][j][off] != -1)
        return memo[i][j][off];
    if(i == j)
        return memo[i][j][off] = best[seg[i] + off];
    ll ans = best[seg[i] + off] + dp(i + 1, j, 0);
    for(int en = i + 2; en <= j; en += 2) {
        ll a = dp(i + 1, en - 1, 0) + dp(en, j, seg[i]);
        //cout << i << " " << en << " " << j << " " << a << endl;
        ans = max(ans, dp(i + 1, en - 1, 0) + dp(en, j, seg[i] + off));
    }
    return memo[i][j][off] = ans;
}
 
int main() {
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++)
        cin >> cost[i];
    best[1] = cost[1];
    for(int i = 2; i <= n; i++) {
        best[i] = cost[i];
        for(int j = 1; j < i; j++)
            best[i] = max(best[i], cost[j] + best[i - j]);
    }
    int sz = 1;
    for(int i = 0; i < n; i++) {
        if(i == n - 1 || s[i] != s[i + 1]) {
            seg.push_back(sz);
            sz = 1;
        }
        else
            sz++;
    }
    memset(memo, -1, sizeof memo);
    /*for(int i = 1; i < seg.size(); i++) {
        for(int j = i; j < seg.size(); j++) {
            cout << "(" << i << ", " << j << "): " << dp(i, j, 0) << endl;
        }
    }
    cout << dp(3, 4, 2) << endl;*/
    cout << dp(1, seg.size() - 1, 0) << endl;
}