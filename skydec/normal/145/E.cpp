#include<stdio.h>
#include<cstring>
#define MAXN 1010000
using namespace std;
char str[MAXN];
int s4[MAXN*4],s7[MAXN*4];
int a47[MAXN*4],a74[MAXN*4];
bool rev[MAXN*4];
int n,m;
//int x,y;
inline int max(int a,int b){if(a>b)return a;return b;}
#define x xs
inline void up(int x)
{
       s4[x]=s4[x*2]+s4[x*2+1];
       s7[x]=s7[x*2]+s7[x*2+1];
       a47[x]=max(max(a47[x*2]+s7[x*2+1],s4[x*2]+a47[x*2+1]),s4[x*2]+s7[x*2+1]);
       a47[x]=max(a47[x],max(s4[x*2]+s4[x*2+1],s7[x*2]+s7[x*2+1]));
       a74[x]=max(max(a74[x*2]+s4[x*2+1],s7[x*2]+a74[x*2+1]),s7[x*2]+s4[x*2+1]);
       a74[x]=max(a74[x],max(s4[x*2]+s4[x*2+1],s7[x*2]+s7[x*2+1]));
}
#undef x
void build(int now,int l,int r)
{
     //printf("%d %d %d\n",now,l,r);
     if(l==r)
     {
             s4[now]=(str[l]=='4');
             s7[now]=(str[l]=='7');
             a47[now]=a74[now]=1;
             return;
             }
     int mid=(l+r)>>1;
     build(now*2,l,mid);
     build(now*2+1,mid+1,r);
     up(now);
}
#define x xs
inline void Rever(int x)
{
       //printf("%d\n",x);
     rev[x]^=1;
     int tmp=s4[x];s4[x]=s7[x];s7[x]=tmp;
     tmp=a47[x];a47[x]=a74[x];a74[x]=tmp;
}
#undef x
inline char getnext()
{
       char p=getchar();
       while(!(p<='9'&&p>='0'))p=getchar();
       return p;
}
#define x xs
inline void down(int x)
{
       if(!rev[x])return;
       rev[x]=0;
       Rever(x*2);
       Rever(x*2+1);
}
#undef x
int x,y;
void Revit(int now,int l,int r)
{
     //printf("%d %d %d\n",now,l,r);
     if(l!=r)
     down(now);
     if(x<=l&&r<=y)
     {
                   Rever(now);
                   return;
                   }
     int mid=(l+r)>>1;
     if(x<=mid)Revit(now*2,l,mid);
     if(y>mid)Revit(now*2+1,mid+1,r);
     up(now);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)str[i]=getnext();
    build(1,1,n);
    while(m--)
    {
              char opt[7];scanf("%s",opt+1);
              //printf("%d %d %d\n",s4[4],s4[5],s7[5]);
              if(opt[1]=='c')printf("%d\n",max(max(a47[1],s4[1]),s7[1]));
              else
              {
                  scanf("%d%d",&x,&y);
                  Revit(1,1,n);
                  }
                  }
    return 0;
}