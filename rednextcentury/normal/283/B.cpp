# include <iostream>
# include <algorithm>
# include <vector>
# include <stdio.h>
using namespace std;
long long ans[1000000][2];
long long vis[1000000][2];
long long a[1000000];
long long n;
long long x;
long long no[1000000][2];
void dfs(int v,bool typ)
{
    if (vis[v][typ]==x) {ans[v][typ]=-1;return;}
    if (vis[v][typ]) return;
    vis[v][typ]=x;
    int h=v;
    if (typ==1)
    {
        v+=a[v];
        ans[h][typ]+=a[h];
        if (v<0 || v>n)
            return;
        dfs(v,1-typ);
    }
    else
    {
        v-=a[v];
        ans[h][typ]+=a[h];
        if (v<0 || v>n)
            return;
        dfs(v,1-typ);
    }
    ans[h][typ]+=ans[v][1-typ];
    if (ans[v][1-typ]==-1)
        ans[h][typ]=-1;
    no[h][typ]=no[v][1-typ];
}
int main()
{
    cin>>n;
    n--;
    for (long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (long long i=1;i<=n;i++)
    {
        if (!vis[i][0])
        {
            vis[0][0]=vis[0][1]=0;
            no[0][0]=no[0][1]=1;
            a[0]=i;
            x=i;
            dfs(i,0);
        }
        if (no[i][0])
            cout<<-1<<endl;
        else if (ans[i][0]>=0)
            cout<<ans[i][0]+i<<endl;
        else
            cout<<ans[i][0]<<endl;
    }
}