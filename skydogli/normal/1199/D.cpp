#include<bits/stdc++.h>
using namespace std;
#define INF 1e9+1
#define MN 400005
int n,q,a[MN],cnt,ans,last[MN],Max[MN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        int op,loc,v;
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&loc,&v);
            a[loc]=v;
            last[loc]=i;
        }
        else{
            scanf("%d",&v);
            Max[i]=v;
        }
    }
    for(int i=q;i>=0;--i)Max[i]=max(Max[i],Max[i+1]);
    for(int i=1;i<=n;++i)
        printf("%d ",max(a[i],Max[last[i]]));
    return 0;
}