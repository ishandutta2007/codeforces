#include<cstdio>

using namespace std;

int n,m,nowans,l1,r1,l2,r2,a[510][510],sum[510][510],Sum[510][510];

char getnext()
{
    char ch=getchar();
    while(ch!='.'&&ch!='#')ch=getchar();
    return ch;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=getnext();
     for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='.'&&a[i][j-1]=='.')sum[i][j]=sum[i][j-1]+1;
            else sum[i][j]=sum[i][j-1];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[j][i]=='.'&&a[j-1][i]=='.')Sum[i][j]=Sum[i][j-1]+1;
            else Sum[i][j]=Sum[i][j-1];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        nowans=0;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        for(int i=l1;i<=l2;i++)
        {
            nowans+=sum[i][r2]-sum[i][r1-1];
            if(a[i][r1]=='.'&&a[i][r1-1]=='.')nowans--;
        }
        for(int i=r1;i<=r2;i++)
        {
            nowans+=Sum[i][l2]-Sum[i][l1-1];
            if(a[l1][i]=='.'&&a[l1-1][i]=='.')nowans--;
        }
        printf("%d\n",nowans);
    }
}