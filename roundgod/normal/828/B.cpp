#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000
using namespace std;
char c[MAXN][MAXN];
int n,m;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",c[i]);
    int x1=INF,x2=-INF,y1=INF,y2=-INF,cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(c[i][j]=='B')
            {
                x1=min(x1,i);
                y1=min(y1,j);
                x2=max(x2,i);
                y2=max(y2,j);
                cnt++;
            }
        }
    if(cnt==0)
    {
        printf("1\n");
        return 0;
    }
    if(max(x2-x1+1,y2-y1+1)>n||max(x2-x1+1,y2-y1+1)>m)
    {
        printf("-1\n");
        return 0;
    }
    else
    {
        printf("%d\n",max(x2-x1+1,y2-y1+1)*max(x2-x1+1,y2-y1+1)-cnt);
        return 0;
    }
}