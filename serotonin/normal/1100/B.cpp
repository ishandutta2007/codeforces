#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=5e5+5;

vector <int> a[sz];
int ans[sz];

int main()
{
    int i,j,n,m,b,x,k=1;
    cin >> n >> m;
    for(i=0; i<m; i++) {
        scanf("%d", &x);
        a[x].push_back(i);
    }
    int mx=sz;
    for(i=1; i<=n; i++) {
        int z=a[i].size();
        mx=min(mx,z);
    }
    for(j=0; j<mx; j++) {
        int now=-1;
        for(i=1; i<=n; i++) {
            now=max(now,a[i][j]);
        }
        ans[now]=1;
    }
    for(i=0; i<m; i++) {
        if(ans[i]) printf("1");
        else printf("0");
    }
}