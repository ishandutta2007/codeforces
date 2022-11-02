#include <stdio.h>
#include <string.h>

main(){
    ///freopen("1.in","r",stdin);
    int n,m,x,y;
    int ans = 0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d %d",&x,&y);
            if(x||y) ans++;
        }
    }
    printf("%d\n",ans);
}