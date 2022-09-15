#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<math.h>
#include<string>
#include<string.h>
#include<math.h>
#include<queue>
using namespace std;

#define li long long
#define db long double
#define mp make_pair
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define vi vector<int>
const int INF =1000000007;

void solve();

int main ()
{
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
#else
	//freopen("necklace.in","r",stdin);
	//freopen("necklace.out","w",stdout);
#endif
	ios_base::sync_with_stdio(false);
	int rt=1;
//	cin>>rt;
	while(rt--)
		solve();
	return 0;
}
//#define int li

vector<int> a,sz;
vector<vi > g;
int find_set(int v)
{
	if(a[v]==v)
		return v;
	return a[v]=find_set(a[v]);
}
void union_set(int v1,int v2)
{
	v1=find_set(v1);
	v2=find_set(v2);
	if(v1!=v2)
	{
		if(sz[v1]<sz[v2])
		{
			a[v1]=v2;
			sz[v2]=sz[v1]+sz[v2];
		}
		else
		{
			a[v2]=v1;
			sz[v1]=sz[v1]+sz[v2];
		}
	}
}
void solve()
{
	int n,m;
//	cin>>n>>m;
	scanf("%d%d", &n, &m);
	g.resize(n);
	for(int i=0;i<m;i++)
	{
		int v1,v2;
		scanf("%d%d", &v1, &v2);
		v1--,v2--;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	a.resize(n);
	sz.resize(n,1);
	for(int i=0;i<n;i++)
	{
		a[i]=i;
	}
	set<int> rr,rr1;
	for(int v=0;v<n;v++)
	{
		rr.insert(v);
		map<int,int> q;
		for(int i=0;i<g[v].size();i++)
		{
			int to=g[v][i];
			int r=find_set(to);
			q[r]++;
		}
		for( set<int>::iterator i=rr.begin();i != rr.end() ;i++)
		{
			int fd=*i;
			if(q[fd]!=sz[find_set(fd)])
			{
				rr1.erase(find_set(fd));
				rr1.erase(find_set(v));
				union_set(v,fd);
				rr1.insert(find_set(v));
			}
		}
		rr=rr1;
	}
	map<int,vi > res;
	for(int i=0;i<n;i++)
	{
		res[find_set(a[i])].push_back(i);
	}
	map<int,vi >::iterator iii=res.begin();
//	cout<<res.size()<<'\n';
	printf("%d\n", res.size() - 1);
	/*while(iii!=res.end())
	{
		vi cur=iii->second;
		iii++;
//		cout<<cur.size()<<' ';
		printf("%d ", cur.size());
		for(int i=0;i<cur.size();i++)
//			cout<<cur[i]+1<<' ';
			printf("%d\n", cur[i] + 1);
//		cout<<endl;
	}*/
}