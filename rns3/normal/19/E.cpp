#include<cstdio>
const int    N=20008;
int en[N],vn[N],suc[N],pc[N],f[N],ans[N],c[N],d[N];
int n,m,p,cnt,a,b;
void ae(int a,int b){en[++p]=vn[a],vn[a]=p,suc[p]=b;}
void dfs(int x,int l){
    pc[x]=1;
    for(int p=vn[x];p;p=en[p]){
        int    y=suc[p];
        if((y==l)||(d[y]>d[x]))continue;
        if(!pc[y])
					d[y]=d[x]+1,dfs(y,x),c[p]=f[y],f[x]+=f[y];
        else if((d[x]&1)==(d[y]&1)) {
            f[x]++,f[y]--,c[p]++,cnt++;
        }
        else  {
            f[x]--,f[y]++;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)scanf("%d%d",&a,&b),ae(a,b),ae(b,a);
    for(int i=1;i<=n;i++)if(!pc[i])dfs(i,0);
    if(!cnt){
        printf("%d\n",m);
        for(int i=1;i<=m;i++)printf("%d ",i);
    }
    else{
        p=0;
        for(int i=1;i<=m+m;i++)if(c[i]==cnt)ans[++p]=(i+1)/2;
        printf("%d\n",p);
        for(int i=1;i<=p;i++)printf("%d ",ans[i]);
    }
}