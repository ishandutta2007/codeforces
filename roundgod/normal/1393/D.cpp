#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str[MAXN];
int d[MAXN][MAXN];
int ans;
int n,m;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
    {
        cin>>str[i];
        str[i]='0'+str[i]+'0';
    }
    str[0]=str[n+1]=string(m+2,'0');
    queue<P> que;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            bool f=false;
            for(int k=0;k<4;k++)
            {
                int nx=i+dx[k],ny=j+dy[k];
                if(str[i][j]!=str[nx][ny]) f=true;
            }
            if(f)
            {
                d[i][j]=1;
                que.push(P(i,j)); 
            }
            else d[i][j]=INF;
        }
    while(que.size())
    {
        P p=que.front();
        que.pop();
        for(int k=0;k<4;k++)
        {
            int nx=p.F+dx[k],ny=p.S+dy[k];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&d[nx][ny]==INF) 
            {
                d[nx][ny]=d[p.F][p.S]+1;
                que.push(P(nx,ny));
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans+=d[i][j];
    printf("%d\n",ans);
    return 0;
}