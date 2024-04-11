#include<cstdio>
#include<cmath>
int n,q,a[100005],b[100005],l[100005],r[100005];
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i-1]=fabs(a[i]-a[i-1]);
    for(int i=1;i<=q;i++){
        int x,y;long long ans=0;
        scanf("%d%d",&x,&y);y--;
        l[x]=x-1;r[y]=y+1;
        for(int j=x+1;j<=y;j++){l[j]=j-1;while(l[j]>=x&&b[l[j]]<b[j]) l[j]=l[l[j]];}
        for(int j=y-1;j>=x;j--){r[j]=j+1;while(r[j]<=y&&b[r[j]]<=b[j]) r[j]=r[r[j]];}
        for(int j=x;j<=y;j++) ans+=(long long)(l[j]-j)*(j-r[j])*b[j];
        printf("%I64d\n",ans);
    }
    return 0;
}