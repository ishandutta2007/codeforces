#include<bits/stdc++.h>
#define R register
using namespace std;
const int N=1005;
const int inf=0x3f3f3f3f;
int n;
int a[N][N],f[2][N][N],dp[2][N][N];
int ans,qx,qy;
bool flag;
inline int get2(R int x,R int y)
{
    if (a[x][y]==0) return 0;
    int cnt=0;
    while(a[x][y]%2==0) cnt++,a[x][y]/=2;
    return cnt;
}
inline int get5(R int x,R int y)
{
    if (a[x][y]==0) return 0;
    int cnt=0;
    while(a[x][y]%5==0) cnt++,a[x][y]/=5;
    return cnt;
}



inline void print(R int k,R int x,R int y,R int first)
{
	
    if (x==1&&y==1) ;
    else if (x==1) print(k,x,y-1,0);
    else if (y==1) print(k,x-1,y,1);
    else if (dp[k][x][y]==dp[k][x-1][y]+f[k][x][y]) print(k,x-1,y,1);
    else print(k,x,y-1,0);
    if (first==inf) return ;
    putchar(first==0?'R':'D');
    return ;
}


inline void read()
{
	for (R int i=1;i<=n;i++)
		{
            for (R int j=1;j<=n;j++)
			{
                scanf("%d",&a[i][j]);
                if (a[i][j]==0)
				{
                    qx=i;qy=j;
                    flag=1;
                } 
            }
        }
}


inline void init()
{
	for (R int i=1;i<=n;i++)
		{
            for (R int j=1;j<=n;j++)
			{
                f[0][i][j]=get2(i,j);
                f[1][i][j]=get5(i,j);
            }
        }
}


inline void solve()
{
	memset(dp,63,sizeof(dp));
    for (R int i=1;i<=n;i++)
        for (R int j=1;j<=n;j++)
		{
            dp[0][i][j]=min(dp[0][i][j],dp[0][i-1][j]);
            dp[0][i][j]=min(dp[0][i][j],dp[0][i][j-1]);
            if (i==1&&j==1) dp[0][i][j]=0;
            dp[0][i][j]+=f[0][i][j];
        }
    for (R int i=1;i<=n;i++)
        for (R int j=1;j<=n;j++)
		{
            dp[1][i][j]=min(dp[1][i][j],dp[1][i-1][j]);
            dp[1][i][j]=min(dp[1][i][j],dp[1][i][j-1]);
            if (i==1&&j==1) dp[1][i][j]=0;
            dp[1][i][j]+=f[1][i][j];
        }
    ans=min(dp[0][n][n],dp[1][n][n]);
}
inline void put()
{
	if (ans>1&&flag==1)
		{
            cout<<1;
            cout<<endl;
            for (R int i=1;i<qx;i++) cout<<"D";
            for (R int i=1;i<qy;i++) cout<<"R";
            for (R int i=qx;i<n;i++) cout<<"D";
            for (R int i=qy;i<n;i++) cout<<"R";
            cout<<endl;
        }
		else
		{
            cout<<ans;
            cout<<endl;
            if (dp[0][n][n]<dp[1][n][n]) print(0,n,n,inf);
            else print(1,n,n,inf);
            cout<<endl;
        }
}
int main()
{
    cin>>n;
	flag=0;qx=0;qy=0;
	read();
	if (a[1][1]==0)
	{
        puts("1");
        for(int i=1;i<=n-1;i++) cout<<"D";
        for(int i=1;i<=n-1;i++) cout<<"R";
        return 0;
    }
	init();
	solve();
	put();
}