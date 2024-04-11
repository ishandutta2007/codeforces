#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
int m,n,i,a[4020][4020],b[4020][4020],x,y,j,k,edge[4020],mini,f,p,record[4020],z;
int main()
{
    mini=21390123;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(edge,0,sizeof(edge));
    memset(record,0,sizeof(record));
    scanf("%d %d",&m,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        edge[x]++;
        edge[y]++;
        record[x]++;
        record[y]++;
        a[x][record[x]]=y;
        a[y][record[y]]=x;
        b[x][y]=1;
        b[y][x]=1;
    }
    for(i=1;i<=m;i++)
        for(j=1;j<=record[i];j++)
            for(k=1;k<=record[a[i][j]];k++)
        {
            f=a[i][j];
            p=a[f][k];
            if(i!=p&&b[p][i]) mini=min(mini,edge[i]+edge[f]+edge[p]);
             
        }
          if(mini==21390123) mini=5;
    printf("%d ",mini-6);
    return 0;
}