#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
struct node
{
	vector<int> v1;
	vector<int> v2;
}cnt,cnt1;
bool operator==(const node &x,const node &y)
{
	return x.v1==y.v1;
}
bool operator<(const node &x,const node &y)
{
	return x.v1<y.v1;
}
void init(node &x)
{
	x.v1.clear();
	x.v2.clear();
}
std::vector<node> S,T;
map<char,int> mp;
int n,m,num[4][4],vis[4][100001],L[4],R[4],ans1[100001],ans2[100001];
std::vector<array<int,2>> G[4][100001];
/*0: L; 1:U; 2: R; 3: D*/
void dfs(int x,int y)
{
	// cout<<x<<" "<<y<<"\n";
	vis[x][y]=1;
	cnt.v1.push_back(x);
	cnt.v2.push_back(y);
	for(auto [u,v]:G[x][y])
		if(!vis[u][v])
			dfs(u,v);
}
node HSH()
{
	int N=cnt.v1.size(),i=0,l=1,j=0;
	while(i<N&&l<N&&j<N)
		if(cnt.v1[(i+j)%N]==cnt.v1[(l+j)%N])
			j++;
		else
		{
			if(cnt.v1[(i+j)%N]<cnt.v1[(l+j)%N])
				l+=j+1;
			else
				i+=j+1;
			if(i==l)
				l++;
			j=0;
		}
	init(cnt1);
	int res=min(i,l);
	for(int p=0;p<N;p++)
	{
		cnt1.v1.push_back(cnt.v1[(p+res)%N]);
		cnt1.v2.push_back(cnt.v2[(p+res)%N]);
	}
	return cnt1;
}
signed main()
{
	mp['T']=1;
	mp['R']=2;
	mp['B']=3;
	n=read();
	m=read();
	for(int i=1;i<=n+m;i++)
	{
		char c1,c2;
		c1=getchar();
		getchar();
		c2=getchar();
		int a=mp[c1],b=mp[c2],x=read(),y=read();
		if(a>b)
		{
			swap(a,b);
			swap(x,y);
		}
		num[a][b]++;
		G[a][x].push_back({b,y});
		G[b][y].push_back({a,x});
	}
	for(int i=1;i<=n;i++)
	{
		G[0][i].push_back({2,i});
		G[2][i].push_back({0,i});
	}
	for(int i=1;i<=m;i++)
	{
		G[1][i].push_back({3,i});
		G[3][i].push_back({1,i});
	}
	if(num[0][2]&&num[1][3])
	{
		puts("No solution");
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int l=0;l<=2;l+=2)
			if(!vis[l][i])
			{
				init(cnt);
				dfs(l,i);
				node k1=HSH();
				reverse(ALL(cnt.v1));
				reverse(ALL(cnt.v2));
				node k2=HSH();
				node k3=min(k1,k2);
				// for(int j:k3.v1)
					// cout<<j<<" ";
				// cout<<'\n';
				S.push_back(min(k1,k2));
			}
	for(int i=1;i<=m;i++)
		for(int l=1;l<=3;l+=2)
			if(!vis[l][i])
			{
				init(cnt);
				dfs(l,i);
				node k1=HSH();
				reverse(ALL(cnt.v1));
				reverse(ALL(cnt.v2));
				node k2=HSH();
				node k3=min(k1,k2);
				// for(int j:k3.v1)
					// cout<<j<<" ";
				// cout<<'\n';
				S.push_back(min(k1,k2));
			}
	// puts("-----------");
	sort(ALL(S));
	for(int i=1;i<=n;i++)
		for(int l=0;l<=2;l+=2)
			G[l][i].clear();
	for(int i=1;i<=m;i++)
		for(int l=1;l<=3;l+=2)
			G[l][i].clear();
	for(int i=1;i<=n;i++)
	{
		L[0]=L[2]=1;
		R[0]=R[2]=n;
		G[0][i].push_back({2,i});
		G[2][i].push_back({0,i});
	}
	for(int i=1;i<=m;i++)
	{
		L[1]=L[3]=1;
		R[1]=R[3]=m;
		G[1][i].push_back({3,i});
		G[3][i].push_back({1,i});
	}
	while(num[0][1]--)
	{
		G[0][L[0]].push_back({1,L[1]});
		G[1][L[1]].push_back({0,L[0]});
		L[0]++;
		L[1]++;
	}
	while(num[1][2]--)
	{
		G[1][R[1]].push_back({2,L[2]});
		G[2][L[2]].push_back({1,R[1]});
		R[1]--;
		L[2]++;
	}
	while(num[2][3]--)
	{
		G[2][R[2]].push_back({3,R[3]});
		G[3][R[3]].push_back({2,R[2]});
		R[2]--;
		R[3]--;
	}
	while(num[0][3]--)
	{
		G[0][R[0]].push_back({3,L[3]});
		G[3][L[3]].push_back({0,R[0]});
		R[0]--;
		L[3]++;
	}
	while(num[0][2]--)
	{
		G[0][L[0]].push_back({2,L[2]});
		G[2][L[2]].push_back({0,L[0]});
		L[0]++;
		L[2]++;
	}
	while(num[1][3]--)
	{
		G[1][L[1]].push_back({3,L[3]});
		G[3][L[3]].push_back({1,L[1]});
		L[1]++;
		L[3]++;
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		for(int l=0;l<=2;l+=2)
			if(!vis[l][i])
			{
				init(cnt);
				dfs(l,i);
				node k1=HSH();
				reverse(ALL(cnt.v1));
				reverse(ALL(cnt.v2));
				node k2=HSH();
				node k3=min(k1,k2);
				// for(int j:k3.v1)
					// cout<<j<<" ";
				// cout<<'\n';
				T.push_back(min(k1,k2));
				// cout<<'\n';
			}
	for(int i=1;i<=m;i++)
		for(int l=1;l<=3;l+=2)
			if(!vis[l][i])
			{
				init(cnt);
				dfs(l,i);
				node k1=HSH();
				reverse(ALL(cnt.v1));
				reverse(ALL(cnt.v2));
				node k2=HSH();
				node k3=min(k1,k2);
				// for(int j:k3.v1)
					// cout<<j<<" ";
				// cout<<'\n';
				T.push_back(min(k1,k2));
				// cout<<'\n';
			}
	sort(ALL(T));
	if(S.size()!=T.size())
	{
		puts("No solution");
		return 0;
	}
	for(int i=0;i<S.size();i++)
		if(S[i]!=T[i])
		{
			puts("No solution");
			return 0;
		}
	for(int i=0;i<S.size();i++)
	{
		for(int l=0;l<S[i].v2.size();l++)
			if(S[i].v1[l]&1)
				ans2[T[i].v2[l]]=S[i].v2[l];
			else
				ans1[T[i].v2[l]]=S[i].v2[l];
	}
	for(int i=1;i<=n;i++)
		cout<<ans1[i]<<" ";
	cout<<'\n';
	for(int i=1;i<=m;i++)
		cout<<ans2[i]<<" ";
	return 0;
}