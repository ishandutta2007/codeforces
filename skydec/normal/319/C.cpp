#include<stdio.h>
#include<cstring>
#define MAXN 110000
using namespace std;
typedef long long LL;
LL a[MAXN],b[MAXN];
LL f[MAXN];
int n;
int q[MAXN];
long double up(int x,int y){return f[y]-f[x];}
long double down(int x,int y){return b[x]-b[y];}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%I64d",&b[i]);
    f[1]=0;
    int tail,top;
    top=tail=1;
    q[1]=1;
    for(int i=2;i<=n;i++)
    {
            while((tail!=top)&&up(q[top],q[top+1])<a[i]*down(q[top],q[top+1]))top++;
            f[i]=f[q[top]]+a[i]*b[q[top]];
            while((tail!=top)&&up(q[tail],i)*down(q[tail-1],q[tail])<down(q[tail],i)*up(q[tail-1],q[tail]))tail--;
            q[++tail]=i;
            }
    printf("%I64d\n",f[n]);
    return 0;
}