#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
const ll MOD = 998244353;
const int MAXN = 1e6 + 10;
 
int dp[1005][1005];
int precol[MAXN], col[MAXN], le[505], ri[505], n, m;
vector<int> positions[505];
 
ll calc(int L, int R) {
    assert(L >= 0);
    assert(R >= 0);
    if(dp[L][R] != -1)
        return dp[L][R];
    if(L == R + 1)
        return 1;

    int color = 1;
    for(; color <= n; color++) {
        if(le[color] >= L && ri[color] <= R)
            break;
    }

    if(color == n + 1)
        return dp[L][R] = 0;
 
    int reL = le[color], reR = ri[color];
 
    ll waysL = calc(L, reL - 1), waysR = calc(reR + 1, R), tot = 1;
    for(int oc = 1; oc <= n; oc++) {
        if(ri[oc] <= reL && le[oc] >= L && oc != color)
            waysL = (waysL + calc(L, le[oc] - 1) * calc(le[oc], reL - 1)) % MOD;
    }
    for(int oc = 1; oc <= n; oc++) {
        if(le[oc] >= reR && ri[oc] <= R && oc != color)
            waysR = (waysR + calc(ri[oc] + 1, R) * calc(reR + 1, ri[oc])) % MOD;
    }
    tot = (waysL * waysR) % MOD;
    for(int i = 1; i < positions[color].size(); i++) {
        if(positions[color][i] > positions[color][i - 1] + 1)
            tot = (tot * calc(positions[color][i - 1] + 1, positions[color][i] - 1)) % MOD;
    }
    return dp[L][R] = tot;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m;
    int pt = 1;
    for(int i = 1; i <= m; i++)
        cin >> precol[i];
    for(int i = 2; i <= m + 1; i++)
        if(precol[i] != precol[i - 1])
            col[pt++] = precol[i - 1];
    m = pt - 1;
    if(m > 2*n) {
        cout << "0\n";
        return 0;
    }
    for(int i = 1; i <= m; i++)
        positions[col[i]].push_back(i);
    for(int i = 1; i <= m; i++)
        ri[col[i]] = i;
    for(int i = m; i >= 1; i--)
        le[col[i]] = i;
    bool bad = false;
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(ri[i] <= ri[j] && ri[i] >= le[j])
                bad = true;
            if(le[i] <= ri[j] && le[i] >= le[j])
                bad = true;
        }
    }
    if(bad) {
        cout << "0\n";
        return 0;
    }
    for(int i = 0; i < 1005; i++)
        for(int j = 0; j < 1005; j++)
            dp[i][j] = -1;

    cout << endl;
    cout << calc(1, m) << '\n';
}