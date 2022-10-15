#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN][MAXN];
bool vis[MAXN][MAXN];
vector<pair<P,int> > ans;
int check(int x,int y)
{
	vector<int> v;
	v.push_back(a[x][y]); v.push_back(a[x+1][y]); v.push_back(a[x][y+1]); v.push_back(a[x+1][y+1]);
	sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
	if(v[0]==0&&v.size()==1) return 0;
	if(v[0]==0&&v.size()==2) return v[1];
	if(v.size()==1) return v[0];
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	memset(vis,false,sizeof(vis));
	queue<pair<P,int> > que;
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m-1;j++)
		{
			int x=check(i,j);
			if(x) {que.push(make_pair(P(i,j),x)); vis[i][j]=true;}
		}
	while(que.size())
	{
		auto p=que.front(); que.pop();
		int x=p.F.F,y=p.F.S,c=p.S;
		ans.push_back(p);
		a[x][y]=a[x+1][y]=a[x][y+1]=a[x+1][y+1]=0;
		for(int i=x-1;i<=x+1;i++)
			for(int j=y-1;j<=y+1;j++)
			{
				if(i==x&&j==y) continue;
				if(i<=0||i>=n||j<=0||j>=m) continue;
				if(!vis[i][j])
				{
					int x=check(i,j);
					if(x) {que.push(make_pair(P(i,j),x)); vis[i][j]=true;}
				}
			}
	}
	bool f=true;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]) f=false;
	if(!f) {puts("-1"); return 0;}
	printf("%d\n",(int)ans.size());
	reverse(ans.begin(),ans.end());
	for(auto p:ans) printf("%d %d %d\n",p.F.F,p.F.S,p.S);
	return 0;
}