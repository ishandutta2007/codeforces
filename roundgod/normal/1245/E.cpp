#include<bits/stdc++.h>
#define MAXN 2005
#define MAXM 5000005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int a[10][10];
db dp[10][10];
P go(P p,int r)
{
    int x=p.F,y=p.S,nx=x,ny=y;
    if(x%2==0)
    {
        int tmp=min(r,ny);
        ny-=tmp; r-=tmp;
        if(r>0)
        {
            if(x==0) return p;
            else return P(nx-1,r-1);
        }
        else return P(nx,ny);
    }
    else
    {
        int tmp=min(r,9-ny);
        ny+=tmp; r-=tmp;
        if(r>0) return P(nx-1,10-r);
        else return P(nx,ny);
    }
}
db solve(int x,int y);
db get_ans(int x,int y)
{
    assert(x>=0&&x<10&&y>=0&&y<10);
    if(a[x][y]==0) return solve(x,y);
    else return min(solve(x,y),solve(x-a[x][y],y));
}
db solve(int x,int y)
{
    if(x==0&&y==0) return 0.0;
    if(dp[x][y]!=-1.0) return dp[x][y];
    dp[x][y]=1e9;
    int cnt;
    db res;
    cnt=0; res=0.0;
    for(int i=1;i<=6;i++)
    {
        P to=go(P(x,y),i);
        assert(to.F<=x);
        if(to.F==x&&to.S==y) cnt++;
        else res+=get_ans(to.F,to.S)/6.0;
    }
    dp[x][y]=min(dp[x][y],(res+1.0)*6/(6-cnt));
    return dp[x][y];
}
int main()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            dp[i][j]=-1.0;
    printf("%.10Lf\n",solve(9,0));
    return 0;
}