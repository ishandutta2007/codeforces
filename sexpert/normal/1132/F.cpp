#include <bits/stdc++.h>
using namespace std;
 
string s;
int memo[502][502];
 
int dp(int l, int r) {
    if(l > r)
        return 0;
    if(memo[l][r] != -1)
        return memo[l][r];
    int d = 1 + dp(l + 1, r);
    for(int i = l + 1; i <= r; i++) {
        if(s[l] == s[i])
            d = min(d, dp(l + 1, i - 1) + dp(i, r));
    }
    return memo[l][r] = d;
}
 
int main() {
    int n;
    cin >> n >> s;
    memset(memo, -1, sizeof memo);
    cout << dp(0, n - 1) << endl;
}