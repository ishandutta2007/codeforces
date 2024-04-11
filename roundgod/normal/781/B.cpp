#include<bits/stdc++.h>
#define MAXN 2005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,V;
char str[MAXN][20];
vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
bool used[MAXN];
int cmp[MAXN];
void add_edge(int from,int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
int scc()
{
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<V;v++)
    {
        if(!used[v]) dfs(v);
    }
    int k=0;
    memset(used,0,sizeof(used));
    for(int i=vs.size()-1;i>=0;i--)
    {
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<2*n;i++)
		scanf("%s",str[i]);
	V=2*n;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			int node1=i*2,node2=i*2+1,node3=j*2,node4=j*2+1;
			if(str[node1][0]==str[node3][0]&&str[node1][1]==str[node3][1]&&str[node1][2]==str[node3][2])
			{
				add_edge(i*2,i*2+1);
				add_edge(j*2,j*2+1);
			}
			if(str[node1][0]==str[node3][0]&&str[node1][1]==str[node3][1]&&str[node2][0]==str[node4][0])
			{
				add_edge(i*2+1,j*2);
				add_edge(j*2+1,i*2);
			}
			if(str[node1][0]==str[node3][0]&&str[node1][1]==str[node3][1]&&str[node1][2]==str[node4][0])
			{
				add_edge(i*2,j*2);
				add_edge(j*2+1,i*2+1);
			}
			if(str[node1][0]==str[node3][0]&&str[node1][1]==str[node3][1]&&str[node2][0]==str[node3][2])
			{
				add_edge(j*2,i*2);
				add_edge(i*2+1,j*2+1);
			}
		}
	scc();
	for(int i=0;i<n;i++)
		if(cmp[i*2]==cmp[i*2+1]) 
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	for(int i=0;i<n;i++)
	{
		if(cmp[2*i]>cmp[2*i+1])
			printf("%c%c%c\n",str[2*i][0],str[2*i][1],str[2*i][2]);
		else
			printf("%c%c%c\n",str[2*i][0],str[2*i][1],str[2*i+1][0]);
	}
	return 0;
}