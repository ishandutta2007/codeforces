#include<stdio.h>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<vector>
#define MAXN 200000
using namespace std;
map<long,long>ls;
map<long,long>ls2;
long TOTX,TOTY;
struct mat
{
       long x,y;
}data[MAXN];
bool c2(long a,long b){return a>b;}
bool cmp(mat a,mat b)
{
     if(a.y!=b.y)return a.y<b.y;
     return a.x<b.x;
}
long xx[MAXN],yy[MAXN];long n;
bool use[10]={false};
long a[10];long cute[10];
bool flag=false;
vector <long> val[MAXN*4];
long checks(long now,long y)
{
     long ans,l,r;ans=0;
     l=1;r=val[now].size();
     while(l<r)
     {
               long mid=(l+r)>>1;
               if(val[now][mid-1]<=y)
               {
                                     l=mid+1;
                                     ans=mid;
                                     }
               else r=mid;
               }
     if(val[now][l-1]<=y)ans=l;
     return ans;
}
long asker(long now,long x,long y,long l,long r,long v)
{
     if(x<=l&&r<=y)
     {
                   return checks(now,v);
                   }
     long reu=0;
     long mid=(l+r)>>1;
     if(x<=mid)reu+=asker(now*2,x,y,l,mid,v);
     if(y>mid)reu+=asker(now*2+1,x,y,mid+1,r,v);
     return reu;
}
long ask(long x,long y)
{
     if(!x||!y)return 0;
     return asker(1,1,x,1,TOTX,y);
}
void check()
{
     long x1,x2,y1,y2;
     if(yy[cute[a[1]]+cute[a[2]]+cute[a[3]]]==yy[cute[a[1]]+cute[a[2]]+cute[a[3]]+1])return;
     if(xx[cute[a[1]]+cute[a[4]]+cute[a[7]]]==xx[cute[a[1]]+cute[a[4]]+cute[a[7]]+1])return;
     if(yy[cute[a[1]]+cute[a[2]]+cute[a[3]]+cute[a[4]]+cute[a[5]]+cute[a[6]]]==yy[cute[a[1]]+cute[a[2]]+cute[a[3]]+cute[a[4]]+cute[a[5]]+cute[a[6]]+1])return;
     if(xx[cute[a[1]]+cute[a[4]]+cute[a[7]]+cute[a[2]]+cute[a[5]]+cute[a[8]]]==xx[cute[a[1]]+cute[a[4]]+cute[a[7]]+cute[a[2]]+cute[a[5]]+cute[a[8]]+1])return;
     x1=xx[cute[a[1]]+cute[a[4]]+cute[a[7]]];
     x2=xx[cute[a[1]]+cute[a[4]]+cute[a[7]]+cute[a[2]]+cute[a[5]]+cute[a[8]]];
     y1=yy[cute[a[1]]+cute[a[2]]+cute[a[3]]];
     y2=yy[cute[a[1]]+cute[a[2]]+cute[a[3]]+cute[a[4]]+cute[a[5]]+cute[a[6]]];
     //printf("%ld %ld %ld %ld\n",x1,x2,y1,y2);
     long a1,a3,a7,a9;
     a1=ask(ls[x1],TOTY)-ask(ls[x1],ls2[y1]-1);
     //printf("%ld %ld %ld\n",ask(TOTX,ls2[y1]-1),ask(ls[x2],TOTY),ask(ls[x2],ls2[y1]-1));
     a3=n-(ask(TOTX,ls2[y1]-1)+ask(ls[x2],TOTY)-ask(ls[x2],ls2[y1]-1));
     a7=ask(ls[x1],ls2[y2]-1);
     a9=ask(TOTX,ls2[y2]-1)-ask(ls[x2],ls2[y2]-1);
     //printf("%ld %ld %ld %ld\n",a1,a3,a7,a9);
     if(a1!=cute[a[1]])return;
     if(a3!=cute[a[3]])return;
     if(a7!=cute[a[7]])return;
     if(a9!=cute[a[9]])return;
     
     flag=true;
     printf("%.2lf %.2lf\n%.2lf %.2lf\n",x1+0.5,x2+0.5,y1-0.5,y2-0.5);
}
void read(long &x)
{
     bool f=false;x=0;
     char s=getchar();
     while(true)
     {
                if(s=='-')
                {
                          f=true;break;
                          }
                if(s<='9'&&s>='0')break;
                }
     if(s=='-')s=getchar();
     while(s<='9'&&s>='0')
     {
                          x*=10;x+=s-48;s=getchar();
                          }
     if(f)x*=-1;
}
void dfs(long step)
{
     if(flag)return;
     if(step>9)
     {
               check();
               return;
               }
     for(long i=1;i<=9;i++)
     if(!use[i])
     {
                use[i]=true;
                a[step]=i;
                dfs(step+1);
                use[i]=false;
                }
}
#define pb push_back
void insert(long now,long l,long r,long v,long y)
{
     if(l==r)
     {
             val[now].pb(y);
             return;
             }
     long mid=(l+r)>>1;
     if(v<=mid)insert(now*2,l,mid,v,y);
     else insert(now*2+1,mid+1,r,v,y);
     val[now].pb(y);
}
void build(long now,long l,long r)
{
     val[now].clear();
     if(l==r)return;
     long mid=(l+r)>>1;
     build(now*2,l,mid);
     build(now*2+1,mid+1,r);
}
int main()
{
    read(n);
    for(long i=1;i<=n;i++)
    {
             read(data[i].x);read(data[i].y);
             xx[i]=data[i].x;yy[i]=data[i].y;
             }
    for(long i=1;i<=9;i++)read(cute[i]);
    sort(xx+1,xx+1+n);
    sort(yy+1,yy+1+n,c2);
    long tot;tot=0;
    for(long i=1;i<=n;i++)
    if(i==1||xx[i]!=xx[i-1])
    {
                            tot++;ls[xx[i]]=tot;
                            }
    TOTX=tot;
    tot=0;
    for(long i=n;i>=1;i--)
    if(i==n||yy[i]!=yy[i+1])
    {
                            tot++;ls2[yy[i]]=tot;
                            }
    for(long i=1;i<=n;i++)
    {
             data[i].x=ls[data[i].x];
             data[i].y=ls2[data[i].y];
             }
    TOTY=tot;
    sort(data+1,data+1+n,cmp);
    build(1,1,TOTX);
    for(long i=1;i<=n;i++)
    {
             insert(1,1,TOTX,data[i].x,data[i].y);       
    }
    for(long i=1;i<=9;i++)a[i]=i;
    for(long sss=1;sss<=362880;sss++)
    {
             check();
             if(flag)break;
             next_permutation(a+1,a+10);
             }
    if(!flag)printf("-1");
    return 0;
}