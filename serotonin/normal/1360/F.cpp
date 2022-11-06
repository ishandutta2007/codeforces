#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 55;

int n, m;
char s[sz][sz];
int dp[11][1<<11];
bool done;

int fnc(int k, int msk, string ans = "")
{
    if(k == m) {
        if(!done) cout << ans << '\n';
        return done = 1;
    }
    if(dp[k][msk] < 0) {
        int now = 0;
        for(int i=0; i<n; i++) {
            int gon = 0;
            for(int j=0; j<n; j++) {
                if(s[j][k] != s[i][k]) gon |= 1<<j;
            }
            if(msk & gon) continue;
            now |= fnc(k+1, msk | gon, ans + s[i][k]);
        }
        dp[k][msk] = now;
    }
    return dp[k][msk];
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++) scanf("%s", s[i]);
        memset(dp, -1, sizeof(dp));
        done = 0;
        if(!fnc(0, 0)) puts("-1");
    }
}