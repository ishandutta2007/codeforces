#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1010
int n,k,a[N];bool f0[2][N],d[N],*f,*g;
int main()
{
    scanf("%d%d",&n,&k);k--;
    memset(a,-1,sizeof a);
    for(int i=0;i<n;i++)scanf("%d",a+i),a[i]--,d[a[i]]=1;
    f=f0[0],g=f0[1];
    f[0]=1;
    int bf=0;
    for(int i=0;i<n;i++)if(!d[i])
    {
        int s=0;bool F=0;
        for(int j=i;j!=-1;j=a[j])
        {
            s++;
            if(j==k)F=1;
        }
        if(F)
        {
            for(int j=k;j!=-1;j=a[j])bf++;
            continue;
        }
        for(int j=0;j<n;j++)g[j]=0;
        for(int j=0;j<n;j++)if(f[j])
            g[j]=1,g[j+s]=1;
        swap(f,g);
    }
    for(int i=0;i<n;i++)
        if(f[i])printf("%d\n",i+bf);
    return 0;
}