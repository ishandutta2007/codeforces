#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char mp[MAXN][MAXN];
int dx[8]={1,1,1,0,0,-1,-1,-1};
int dy[8]={0,1,-1,1,-1,0,1,-1};
bool valid(int x,int y)
{
    if(mp[x][y]=='*') return true;
    int cnt=mp[x][y]=='.'?0:mp[x][y]-'0';
    for(int i=0;i<8;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&mp[nx][ny]=='*') cnt--;
    }
    return (cnt==0);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",mp[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!valid(i,j)) {puts("No"); return 0;}
    puts("Yes");
    return 0;
}