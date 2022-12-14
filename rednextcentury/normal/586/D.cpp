#include<bits/stdc++.h>
using namespace std;
bool has[111][3][111];
char mp[3][111];
bool vis[111][3][111];
bool is;
int n;
void dfs(int i,int j,int tim)
{
    if (i<0 || i>2 || has[tim][i][j] || vis[tim][i][j])
        return;
    if (j==n)
    {
        is=1;
        return;
    }
    vis[tim][i][j]=1;
    if (!has[tim][i][j+1])
    {
    dfs(i,j+1,tim+1);
        if (i-1>=0 && !has[tim][i-1][j+1])
    dfs(i-1,j+1,tim+1);
        if (i+1<=2 && !has[tim][i+1][j+1])
    dfs(i+1,j+1,tim+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    memset(has,0,sizeof(has));
    memset(vis,0,sizeof(vis));
    is=0;
    int k;
    cin>>n>>k;
    for (int i=0;i<3;i++)
        for (int j=0;j<n;j++)
            cin>>mp[i][j],has[0][i][j]=(mp[i][j]!='.' && mp[i][j]!='s');
    for (int h=1;h<=n;h++)
    {
        for (int i=0;i<3;i++)
            for (int j=0;j<n;j++)
                if (has[h-1][i][j+2])
                    has[h][i][j]=1;
    }
    int st=0;
    while(mp[st][0]!='s') st++;
    dfs(st,0,0);
    if (is)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }
}