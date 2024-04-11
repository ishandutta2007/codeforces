#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,k,x[210];
int main(){
    scanf("%d",&t);
    while (t--){
        scanf("%d%d",&n,&k);
        for (int i=1; i<=k; i++) scanf("%d",&x[i]);
        int ans=0;
        for (int i=1; i<=n; i++){
            int dis=1e9;
            for (int j=1; j<=k; j++) dis=min(dis,abs(x[j]-i)+1);
            ans=max(ans,dis);
        }
        printf("%d\n",ans);
    }
    return 0;
}