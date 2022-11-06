#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

char s[sz];
int a[sz], dp[sz][2];
int n, k;

int fnc(int x, int f)
{
    if(x < 0) return 0;
    if(dp[x][f] < 0) {
        int now = 0;
        if(f) {
            if(s[x] == '0') now++;
            now += min(fnc(x-k, 1), fnc(x-k, 0));
        }
        else {
            if(s[x] == '1') now++;
            now += fnc(x-k, 0);
        }
        dp[x][f] = now;
    }
    return dp[x][f];
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        scanf("%d %d %s", &n, &k, s);

        int on = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '1') on++, a[i] = 1;
            else a[i] = 0;
            if(i >= k) a[i] += a[i-k];
            dp[i][0] = dp[i][1] = -1;
        }

        int ans = on;
        for(int i=0; i<n; i++) {
            int now = min(fnc(i,1), fnc(i,0));
            now += on - a[i];
            ans = min(ans, now);
        }

        printf("%d\n", ans);
    }
}