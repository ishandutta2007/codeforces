#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,d,ans;
int p[N],d1[N],d2[N];
vector<int> T[N];

void dfs(int fa,int u,int deep,int dep[])
{
    dep[u]=deep;
    for(int i=0;i<T[u].size();i++)
	{
        int v=T[u][i];
        if(fa!=v) dfs(u,v,deep+1,dep);
    }
}
int main()
{   
	scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<=m;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n-1;i++)
	{
        int x,y;
        scanf("%d%d",&x,&y);
        T[x].push_back(y);
        T[y].push_back(x);    
    }
    dfs(0,1,0,d1);
    int tmp=0;
    for(int i=1;i<=m;i++) if(d1[p[i]]>d1[tmp]) tmp=p[i];
    dfs(0,tmp,0,d1);
    tmp=0;
    for(int i=1;i<=m;i++) if(d1[p[i]]>d1[tmp]) tmp=p[i];
    dfs(0,tmp,0,d2);
    for(int i=1;i<=n;i++) if(d1[i]<=d && d2[i]<=d) ans++;
    cout<<ans<<endl;
    
}