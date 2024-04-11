#include<cstdio>
#include<algorithm>
using namespace std;
int t,n;
int main(){
    scanf("%d",&t);
    while (t--){
        scanf("%d",&n);
        int nowtime=0;
        for (int i=1; i<=n; i++){
            int l,r;
            scanf("%d%d",&l,&r);
            if (l>nowtime) nowtime=l;
            if (r>=nowtime){
                printf("%d ",nowtime);
                nowtime++;
            }else printf("%d ",0);
        }
        puts("");
    }
    return 0;
}