#include<stdio.h>
#include<cstring>
#define MAXN 1<<24
using namespace std;
int f[MAXN];
int n;int m=24;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
            char opt[5];scanf("%s",opt+1);
            int u1=opt[1]-'a';
            int u2=opt[2]-'a';
            int u3=opt[3]-'a';
            f[1<<u1]++;
            f[1<<u2]++;
            f[1<<u3]++;
            f[(1<<u1)|(1<<u2)]--;
            f[(1<<u3)|(1<<u2)]--;
            f[(1<<u1)|(1<<u3)]--;
            f[(1<<u1)|(1<<u3)|(1<<u2)]++;
            }
    for(int i=0;i<m;i++)
    for(int j=(1<<24)-1;j>=0;j--)
    if(j&(1<<i))f[j]+=f[j-(1<<i)];
    int ans=0;
    for(int i=0;i<MAXN;i++)ans^=(f[i]*f[i]);
    printf("%d\n",ans);
    return 0;
}