#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1550
const int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
char s[N][N];int n,m,px,py,wx[N][N],wy[N][N];bool v[N][N];int qx[N*N],qy[N*N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]=='S')px=i,py=j;
    s[px][py]='.',v[px][py]=1;
    int le=0,ri=1;qx[0]=px,qy[0]=py;
    while(le<ri)
    {
        int x0=qx[le],y0=qy[le];le++;
        for(int d=0;d<4;d++)
        {
            int x1=x0+dx[d],y1=y0+dy[d];
            int ux=wx[x0][y0],uy=wy[x0][y0];
            if(x1<0)x1+=n,ux--;
            if(x1>=n)x1-=n,ux++;
            if(y1<0)y1+=m,uy--;
            if(y1>=m)y1-=m,uy++;
            if(s[x1][y1]!='.')continue;
            if(v[x1][y1])if(ux!=wx[x1][y1]||uy!=wy[x1][y1]){puts("Yes");return 0;}else continue;
            v[x1][y1]=1;wx[x1][y1]=ux,wy[x1][y1]=uy;
            qx[ri]=x1,qy[ri]=y1;ri++;
        }
    }
    puts("No");
    return 0;
}