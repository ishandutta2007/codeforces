/*************************************************************************
    > File Name: E1.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-31 23:03:10
 ************************************************************************/

#pragma GCC optimize(3)
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
struct node{int x,y,num;};
vector<node> ans;
bool used[MAXN][MAXN];
int main()
{
    int cnt=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",mp[i]);
    memset(used,false,sizeof(used));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]=='*')
            {
                cnt=0;
                for(int k=1;;k++)
                {
                    if(i-k<0||mp[i-k][j]!='*') break;
                    if(i+k>=n||mp[i+k][j]!='*') break;
                    if(j-k<0||mp[i][j-k]!='*') break;
                    if(j+k>=m||mp[i][j+k]!='*') break;
                    cnt++;
                }
                if(cnt>=1) ans.push_back((node){i+1,j+1,cnt});
                if(cnt>=1) used[i][j]=true;
                for(int k=1;k<=cnt;k++) used[i-k][j]=used[i][j-k]=used[i+k][j]=used[i][j+k]=true;
            }
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mp[i][j]=='*'&&!used[i][j]) {puts("-1"); return 0;}
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();i++) printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].num);
    return 0;
}