#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
map<string,int> mp;
string s[MAXN],t[MAXN];
int id[MAXN];
int color[MAXN];
vector<int> G[MAXN];
vector<int> order;
void dfs_visit(int v)
{
	color[v]=1;
	for(int i=0;i<G[v].size();i++)
	{
		int to=G[v][i];
		if(!color[to]) dfs_visit(to);
        else if(color[to]==1) {puts("NO"); exit(0);}
	}
    color[v]=2;
	order.push_back(v);
}
void toposort()
{
	memset(color,0,sizeof(color));
	for(int i=1;i<=n;i++)
		if(!color[i])
			dfs_visit(i);
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        mp[s[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>t[i];
        scanf("%d",&id[i]);
        for(int j=0;j<k;j++) 
        {
            if(s[id[i]][j]!='_'&&s[id[i]][j]!=t[i][j]) {puts("NO"); return 0;}
        }
        for(int j=0;j<(1<<k);j++)
        {
            string tmp=t[i];
            for(int l=0;l<k;l++)
                if(j&(1<<l)) tmp[l]='_';
            if(mp.find(tmp)!=mp.end()&&mp[tmp]!=id[i]) 
            {
                G[id[i]].push_back(mp[tmp]);
            }
        }
    }
    toposort();
    puts("YES");
    reverse(order.begin(),order.end());
    for(auto v:order) printf("%d ",v);
    puts("");
}