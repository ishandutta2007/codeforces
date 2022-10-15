#include <bits/stdc++.h>
#define MAXN 255
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int dp[MAXN][(1<<16)][2][2];
int n,m;
char str[MAXN][MAXN];
char g[MAXN][MAXN];
int DFS(int pos,int state,int pre,int cnt)
{
    int x=pos/m;
    int y=pos%m;
    if(y==0) pre=0;
    if(x==n) return 1;
    if(dp[pos][state][pre][cnt]!=-1) return dp[pos][state][pre][cnt];
    int tmp=0;
    if(g[x][y]=='x') return dp[pos][state][pre][cnt]=DFS(pos+1,state&(~(1<<y)),0,cnt);
    else
    {
        tmp=(tmp+DFS(pos+1,state|(1<<y),1,cnt))%MOD;
        if(pre==1||(state>>y)&1) tmp=(tmp+DFS(pos+1,state,pre,cnt))%MOD;
        else if(cnt<1) tmp=(tmp+DFS(pos+1,state,pre,cnt+1))%MOD;
        return dp[pos][state][pre][cnt]=tmp;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(m<=15) cin>>g[i][j];
            else cin>>g[j][i];
        }
    }
    if(m>15) swap(n,m);
    memset(dp,-1,sizeof dp);
    DFS(0,0,0,0);
    printf("%d\n", dp[0][0][0][0]);
    return 0;
}