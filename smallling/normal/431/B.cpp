#include<cstdio>
#include<algorithm>

using namespace std;

int f[6][6],b[6],o,a[6],ans;

void ss(int x)
{
    if(x==5)
    {
        int now=0;
        for(int i=1;i<=5;i++)
            for(int j=i;j+1<=5;j+=2)
                now+=f[a[j]][a[j+1]]+f[a[j+1]][a[j]];
        ans=max(ans,now);
    }
    for(int i=1;i<=5;i++)
    if(!b[i])
    {
        b[i]=1;
        a[++o]=i;
        ss(x+1);
        o--;
        b[i]=0;
    }
}

int main()
{
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
            scanf("%d",&f[i][j]);
    ss(0);
    printf("%d",ans);
}