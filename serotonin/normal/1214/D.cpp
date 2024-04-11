#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=1e6+5;

int main()
{
    int n,m;
    cin >> n >> m;
    char s[n+5][m+5];
    bool d[n+5][m+5], u[n+5][m+5];
    memset(d, 0, sizeof(d));
    memset(u, 0, sizeof(u));

    for(int i=0; i<n; i++) scanf("%s", s[i]);

    d[n-1][m-1]=1;
    for(int i=n-1; i>=0; i--) {
        for(int j=m-1; j>=0; j--) {
            if(s[i][j]=='#') d[i][j]=0;
            if(j) d[i][j-1]|=d[i][j];
            if(i) d[i-1][j]|=d[i][j];
        }
    }

    /* DUMBASS */
    u[0][0]=1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(s[i][j]=='#') u[i][j]=0;
            if(j<m) u[i][j+1]|=u[i][j];
            if(i<n) u[i+1][j]|=u[i][j];
        }
    }

    int ans=n, c[n+m]={0};
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            c[i+j]+=d[i][j]&u[i][j];
        }
    }
    for(int i=1; i<n+m-2; i++) ans=min(ans, c[i]);
    cout << ans;
}