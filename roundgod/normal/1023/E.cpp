/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-17 23:31:15
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> up,down;//0: right 1:down
bool vis[MAXN][MAXN];
char str[5];
void solve1()
{
    int x=n,y=n;
    vis[x][y]=true;
    while(x+y>n+1)
    {
        printf("? %d %d %d %d\n",1,1,x,y-1);
        fflush(stdout);
        scanf("%s",str);
        if(str[0]=='Y')
        {
            y--;vis[x][y]=true;
            down.push_back(0);
        }
        else
        {
            x--;vis[x][y]=true;
            down.push_back(1);
        }
    }
}
void solve2()
{
    int x=1,y=1;
    vis[x][y]=true;
    while(x+y<n+1)
    {
        printf("? %d %d %d %d\n",x+1,y,n,n);
        fflush(stdout);
        scanf("%s",str);
        if(str[0]=='Y')
        {
            x++;vis[x][y]=true;
            up.push_back(1);
        }
        else
        {
            y++;vis[x][y]=true;
            up.push_back(0);
        }
    }
}
int main()
{
    scanf("%d",&n);
    memset(vis,false,sizeof(vis));
    solve1();
    solve2();
    printf("! ");
    for(int i=0;i<(int)up.size();i++)
        if(up[i]==1) printf("D"); else printf("R");
    for(int i=(int)down.size()-1;i>=0;i--)
        if(down[i]==1) printf("D"); else printf("R");
    printf("\n");
    return 0;
}