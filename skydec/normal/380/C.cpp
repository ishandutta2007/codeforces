#include<stdio.h>
#include<cstring>
#define MAXN 4050000
using namespace std;
struct Info
{
       int l,r,ans;
       void make(char lnm)
       {
            l=r=ans=0;
            if(lnm=='(')l=1;
            if(lnm==')')r=1;
            }
       Info operator +(Info b)
       {
            Info reu;
            reu.ans=ans+b.ans;
            int u=l;
            if(b.r<u)u=b.r;
            reu.ans+=u;
            reu.l=b.l+l-u;
            reu.r=b.r+r-u;
            return reu;
            }
}sum[MAXN];
int n,m;
char str[MAXN];
Info ask(int now,int l,int r,int x,int y)
{
     if(x<=l&&r<=y)return sum[now];
     int mid=(l+r)>>1;
     Info ans;
     ans.l=ans.r=ans.ans=0;
     if(x<=mid)ans=ans+ask(now*2,l,mid,x,y);
     if(y>mid)ans=ans+ask(now*2+1,mid+1,r,x,y);
     return ans;
}    
void build(int now,int l,int r)
{
     if(l==r){sum[now].make(str[l]);return;}
     int mid=(l+r)>>1;
     build(now*2,l,mid);
     build(now*2+1,mid+1,r);
     sum[now]=sum[now*2]+sum[now*2+1];
}
int main()
{
    scanf("%s",str+1);n=strlen(str+1);
    build(1,1,n);
    scanf("%d",&m);
    while(m--)
    {
              int l,r;scanf("%d%d",&l,&r);
              printf("%d\n",ask(1,1,n,l,r).ans*2);
              }
    return 0;
}