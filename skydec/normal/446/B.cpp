#include<stdio.h>
#include<cstring>
#define MAXN 1005
using namespace std;
typedef long long LL;
int a[MAXN][MAXN];
void read(int &x)
{
     char p=getchar();
     x=0;
     while(!(p<='9'&&p>='0'))p=getchar();
     while(p<='9'&&p>='0')x*=10,x+=p-48,p=getchar();
}
int n,m,k,p;
int hang[MAXN];
int lie[MAXN];
LL heap[MAXN*2];
int size=0;
void up(int x)
{
     while(x!=1&&heap[x]>heap[x/2])
     {
                 LL tmp=heap[x];
                 heap[x]=heap[x/2];
                 heap[x/2]=tmp;
                 x/=2;
                 }
}
void down(int x)
{
     if(x>size)return;
     int mins=x;
     if(x*2<=size&&heap[x*2]>heap[mins])mins=x*2;
     if(x*2+1<=size&&heap[x*2+1]>heap[mins])mins=x*2+1;
     if(mins!=x)
     {
                LL tmp=heap[x];heap[x]=heap[mins];heap[mins]=tmp;
                down(mins);
                }
}
LL pop()
{
    LL u=heap[1];heap[1]=heap[size--];
    down(1);
    return u;
}
void push(LL x)
{
     heap[++size]=x;
     up(size);
}
long long lk[1010000];
long long hk[1010000];
int main()
{
    scanf("%ld%ld%ld%ld",&n,&m,&k,&p);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
            read(a[i][j]);
            hang[i]+=a[i][j];
            lie[j]+=a[i][j];
            }
    size=0;
    for(int i=1;i<=n;i++)push(1ll*hang[i]);
    for(int i=1;i<=k;i++)
    {
            LL u=pop();
            hk[i]=hk[i-1]+1ll*u;
            //printf("%I64d\n",hk[i]);
            u-=1ll*p*LL(m);
            push(u);
    }
    size=0;
    memset(heap,0,sizeof heap);
    for(int i=1;i<=m;i++)push(1ll*lie[i]);
    for(int i=1;i<=k;i++)
    {
            LL u=pop();
            lk[i]=lk[i-1]+1ll*u;
            //printf("%I64d\n",lk[i]);
            u-=1ll*p*LL(n);
            push(u);
    }
    long long ans=0;bool fl=false;
    for(int i=0;i<=k;i++)
    {
                    long long tmp=hk[i];
                    tmp+=lk[k-i]-1ll*((long long)(k-i)*(long long)(i)*(long long)(p));
                    if((!fl)||ans<tmp){ans=tmp;fl=true;}
                    //printf("%d %I64d\n",i,tmp);
                    }
    printf("%I64d\n",ans);
    return 0;
}