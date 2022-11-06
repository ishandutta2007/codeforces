#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=2e5+5;

pair <int,int> p[sz];
int d[sz];
vector <int> dp[sz], g[sz];

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) scanf("%d", &p[i].first), p[i].second=i;
    sort(p+1, p+n+1);

    for(int i=n, j=0; i; i--, j++) {
        int y=p[i].second, x=p[i].first;
        if(!d[j]) d[j]=2*y-1;
        else dp[j+1].push_back(2*y-1);
        if(!d[j+x]) d[j+x]=2*y;
        else {
            if(x>1) dp[j+x-1].push_back(2*y);
            else g[2*y].push_back(2*y-1);
        }
    }

    for(int i=0; d[i]; i++) {
        int u=d[i];
        if(i) g[u].push_back(d[i-1]);
        for(int j=0; j<dp[i].size(); j++) {
            g[u].push_back(dp[i][j]);
        }
    }

    for(int i=1; i<=2*n; i++) {
        for(int j=0; j<g[i].size(); j++) {
            printf("%d %d\n", i, g[i][j]);
        }
    }
}