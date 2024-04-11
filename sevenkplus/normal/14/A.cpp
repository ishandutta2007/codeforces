#include<cstdio>
#include<algorithm>
using namespace std;
char a[100][100];
int n,m,x1=100,x2=-1,y1=100,y2=-1;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;scanf("%s",a[i]),i++);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]=='*')
                x1=min(x1,i),x2=max(x2,i),y1=min(y1,j),y2=max(y2,j);
    for(int i=x1;i<=x2;i++)
    {
        for(int j=y1;j<=y2;j++)
            putchar(a[i][j]);
        puts("");
    }
    return 0;
}