#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int a[102][102],mn[102];
int main(){
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=1;i<=n;i++){
        mn[i]=1e9+7;
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            mn[i]=min(mn[i],a[i][j]);
        }
        ans=max(ans,mn[i]);
    }
    cout<<ans<<endl;
}