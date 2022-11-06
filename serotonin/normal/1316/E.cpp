#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+5;

typedef pair <int,int> pii;
#define x first
#define y second

int n,p,k;
pii a[sz];
int s[sz][7];
ll dp[sz][1<<7];

ll fnc(int r, int msk, int aud)
{
    if(!r) return 0;

    if(dp[r][msk]<0) {
        ll now = 0;
        if(aud) now = a[r].x + fnc(r-1, msk, aud-1);
        else now = fnc(r-1, msk, aud);

        for(int i=0, id=a[r].y; i<p; i++) {
            if(msk & (1<<i)) {
                now = max(now, s[id][i] + fnc(r-1, msk ^ (1<<i), aud));
            }
        }
        dp[r][msk]=now;
    }
    return dp[r][msk];
}

int main()
{
    cin >> n >> p >> k;
    for(int i=1; i<=n; i++) scanf("%d", &a[i].x), a[i].y=i;
    sort(a+1,a+n+1);

    for(int i=1; i<=n; i++) {
        for(int j=0; j<p; j++) {
            scanf("%d", &s[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << fnc(n, (1<<p)-1, k);
}