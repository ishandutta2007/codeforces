#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100010
#define P 1000000007
char s[N*2];int n,a[N*2],b[N],c[N],p[N],f[N*4],g[N*4],S=0,T,L1,R1,L2,R2,L3,R3;
int hh(int l,int r){return a[r]-a[l-1]*p[r-l+1];}
int rh(int l,int r){return a[n+n+1-l]-a[n+n+1-r-1]*p[r-l+1];}
void upd(int p,int a){f[p]=min(f[p],a),g[p]=min(g[p],a);}
void upd(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R){upd(p,L);return;}
    upd(p*2,g[p]),upd(p*2+1,g[p]),g[p]=P;
    int m=(l+r)/2;
    if(L<=m)upd(p*2,l,m,L,R);
    if(m<R)upd(p*2+1,m+1,r,L,R);
    f[p]=min(f[p*2],f[p*2+1]);
}
int ask(int p,int l,int r,int a)
{
    if(l==r){return f[p];}
    upd(p*2,g[p]),upd(p*2+1,g[p]),g[p]=P;
    int m=(l+r)/2;
    if(a<=m)return ask(p*2,l,m,a);
    if(m<a)return ask(p*2+1,m+1,r,a);
}
int main()
{
    scanf("%s",s+1);n=strlen(s+1);
    for(int i=1;i<=n;i++)s[n+n+1-i]=s[i];
    for(int i=1;i<=n*2;i++)a[i]=a[i-1]*P+s[i];
    p[0]=1;for(int i=1;i<=n;i++)p[i]=p[i-1]*P;
    for(int i=1;i<=n*4;i++)f[i]=g[i]=P;
    for(int i=1;i<=n;i++)
    {
        int L=1,R=n-i+1;
        while(L<=R)
        {
            int M=(L+R)/2;
            if(hh(i,i+M-1)==rh(n-M+1,n))L=M+1;else R=M-1;
        }
        if(R)upd(1,1,n,i,i+R-1);
    }
    for(int i=1;i<=n;i++)
    {
        b[i]=max(b[i-1],i-ask(1,1,n,i)+1);
        if(b[i]==b[i-1])c[i]=c[i-1];else c[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int L=1,R=min(i,n-i+1);
        while(L<=R)
        {
            int M=(L+R)/2;
            if(hh(i,i+M-1)==rh(i-M+1,i))L=M+1;else R=M-1;
        }
        L=min(b[i-R],n-(i+R-1));
        if(L)
        {
            if(L*2+R*2-1>S)
                S=L*2+R*2-1,T=3,
                L1=c[i-R]-b[i-R]+1,R1=c[i-R]-b[i-R]+L,
                L2=i-R+1,R2=i+R-1,
                L3=n-L+1,R3=n;
        }else
        {
            if(R*2-1>S)
                S=R*2-1,T=1,
                L1=i-R+1,R1=i+R-1;
        }
    }
    printf("%d\n",T);
    if(T==1)printf("%d %d\n",L1,R1-L1+1);
    else printf("%d %d\n%d %d\n%d %d\n",L1,R1-L1+1,L2,R2-L2+1,L3,R3-L3+1);
    return 0;
}