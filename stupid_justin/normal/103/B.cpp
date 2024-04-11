#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int inf=0x3f3f3f;
vector<int> vec[N];
void add(int u,int v)
{
	vec[u].push_back(v);
	vec[v].push_back(u);
}
bool vis[N];
int cnt;
void dfs(int x)
{
	vis[x]=1;
	cnt++;
	for (int i=0;i<vec[x].size();i++)
		if (!vis[vec[x][i]]) dfs(vec[x][i]);
}
int n,m;
int main()
{
	cin>>n>>m;
//	cout<<cnt<<" "<<n<<" "<<m<<endl;
	for (int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
	}
	dfs(1);
//	cout<<cnt<<" "<<n<<" "<<m<<endl;
	if (cnt==n && n==m) cout<<"FHTAGN!"<<endl;
	else cout<<"NO"<<endl;
}