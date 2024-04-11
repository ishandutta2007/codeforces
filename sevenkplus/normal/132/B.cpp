#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m,p;char s[60][60];int px[60][60][8],py[60][60][8],pz[60][60][8];
int main()
{
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    m=strlen(s[1]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<8;k++)
            {
                int d1=k/2,d2=(((k&1)?(d1+1):(d1-1))+4)&3;
                int x=i,y=j,x1,y1;
                while(1)
                {
                    x1=x+dx[d1],y1=y+dy[d1];
                    if(x1<1||x1>n||y1<1||y1>m||s[x1][y1]=='0'||s[x1][y1]!=s[i][j])break;
                    x=x1,y=y1;
                }
                while(1)
                {
                    x1=x+dx[d2],y1=y+dy[d2];
                    if(x1<1||x1>n||y1<1||y1>m||s[x1][y1]=='0'||s[x1][y1]!=s[i][j])break;
                    x=x1,y=y1;
                }
                x1=x+dx[d1],y1=y+dy[d1];
                if(x1<1||x1>n||y1<1||y1>m||s[x1][y1]=='0')
                {
                    px[i][j][k]=x,py[i][j][k]=y;
                    if(~k&1)pz[i][j][k]=k^1;
                    else pz[i][j][k]=((k/2+1)&3)*2;
                }else px[i][j][k]=x1,py[i][j][k]=y1,pz[i][j][k]=k;
            }
    int wx=1,wy=1,wz=0,wx1,wy1,wz1;
    while(p--)wx1=px[wx][wy][wz],wy1=py[wx][wy][wz],wz1=pz[wx][wy][wz],wx=wx1,wy=wy1,wz=wz1;
    printf("%c\n",s[wx][wy]);
    return 0;
}