#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
bool f[111][111][4],v[111][111];vector<int> T;
int w,h,n;
void ff(int x,int y,int&s)
{
    if(x<0||x>=w||y<0||y>=h||v[x][y])return;
    s++,v[x][y]=1;
    for(int i=0;i<4;i++)if(!f[x][y][i])ff(x+dx[i],y+dy[i],s);
}
int main()
{
    scanf("%d%d%d",&w,&h,&n);
    for(int i=0;i<n;i++)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(mp(x1,y1)>mp(x2,y2))swap(x1,x2),swap(y1,y2);
        if(x1==x2){for(int j=y1;j<y2;j++)f[x1-1][j][0]=f[x1][j][1]=1;}
        else{for(int j=x1;j<x2;j++)f[j][y1-1][2]=f[j][y1][3]=1;}
    }
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
            if(!v[i][j])
            {
                int S=0;
                ff(i,j,S);
                T.pb(S);
            }
    sort(T.begin(),T.end());
    for(int i=0;i<(int)T.size();i++)printf("%d%c",T[i],i==(int)T.size()-1?'\n':' ');
    return 0;
}