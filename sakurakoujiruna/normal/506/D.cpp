#include <iostream>
#include <map>
#include <set>
#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

const int N = 1564 * 64;
const int P = 1000007;

int h(pair <int, int> p)
{
	return (p.first + p.second * 2333) % P;
}

int cnt = 0;
struct Hash
{
	vector <pair <pair <int, int>, int> > re[P];
	inline int query(const pair <int, int> &q)
	{
		cnt ++;
		int hs = h(q);
		for(auto &p : re[hs])
		{
			cnt ++;
			if(p.first == q)
				return p.second;
		}
		return q.first;
	}
	inline void change(const pair <int, int> &q, int c)
	{
		cnt ++;
		int hs = h(q);
		for(auto &p : re[hs])
			if(p.first == q)
			{
				cnt ++;
				p.second = c;
				return;
			}
		re[hs].push_back({q, c});
	}
}hsh;

namespace Find
{
	inline int find(int x, int c)
	{
		int t = hsh.query({x, c});
		if(t == x)
			return x;
		int ret = find(t, c);
		hsh.change({x, c}, ret);
		return ret;
	}
}

const int Sqrt = 320;
set <int> cc[N];
vector <int> ccc[N];

int main()
{
	using namespace Find;
	//ios :: sync_with_stdio(false);
	int n, m;
	//cin >> n >> m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i ++)
	{
		int u, v, c;
		//cin >> u >> v >> c;
		scanf("%d%d%d", &u, &v, &c);
		cc[u].insert(c);
		cc[v].insert(c);
		int a = find(u, c);
		int b = find(v, c);
		if(a != b)
			hsh.change({a, c}, b);
	}
	for(int i = 1; i <= n; i ++)
		for(const int &c : cc[i])
			ccc[i].push_back(c);

	int q;
	//cin >> q;
	scanf("%d", &q);
	map <pair <int, int>, int> his;
	for(int i = 0; i < q; i ++)
	{
		int u, v;
		//cin >> u >> v;
		scanf("%d%d", &u, &v);
		if(u > v)
			swap(u, v);
		if(his.find({u, v}) != his.end())
		{
			printf("%d\n", his[{u, v}]);
			continue;
		}
		int ans = 0;
		if(cc[u].size() > cc[v].size())
		{
			for(const int &c : ccc[v])
				if(find(u, c) == find(v, c))
					ans ++;
		}
		else
			for(const int &c : ccc[u])
				if(find(u, c) == find(v, c))
					ans ++;
		his[{u, v}] = ans;
		printf("%d\n", ans);
	}
	
	return 0;
}