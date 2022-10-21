#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int savee[40005][1005];

int ans[10005],x[10005],r[10005];

int minx,maxx,n,m,xx,y,maxy,nub;

int main()
    {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        {
        scanf("%d %d",&x[i],&r[i]);
        x[i]+=20000;
        }
    scanf("%d",&m);
    for(int j=1;j<=m;j++)
        {
        scanf("%d %d",&xx,&y);
        xx+=20000;
        if(y<0) y=-y;
        if(y>1000)
            {
            continue;
            }
        if(savee[xx][y]==0) savee[xx][y]=j;
        }
    for(int i=0;i<=40000;i++)
        {
        for(int j=1;j<=1000;j++)
            {
            if(savee[i][j]==0) savee[i][j]=savee[i][j-1];
            else if(savee[i][j-1]!=0) savee[i][j]=min(savee[i][j-1],savee[i][j]);
            }
        }
    for(int i=1;i<=n;i++)
        {
        minx=x[i]-r[i];
        minx=max(0,minx);
        maxx=x[i]+r[i];
        maxx=min(40000,maxx);
        ans[i]=1000000;
        for(int j=minx;j<=maxx;j++)
            {
            maxy=(int)(sqrt(r[i]*r[i]-(x[i]-j)*(x[i]-j)));
            if((maxy+1)*(maxy+1)+(x[i]-j)*(x[i]-j)<=r[i]*r[i]) maxy++;
            if(savee[j][maxy]!=0) ans[i]=min(ans[i],savee[j][maxy]);
            }
        if(ans[i]==1000000)  ans[i]=-1;
        else nub++;
        }
    printf("%d\n",nub);
    for(int i=1;i<=n;i++)
        {
        printf("%d ",ans[i]);
        }
    printf("\n");
    }