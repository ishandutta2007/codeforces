#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int lb = 30;
const int MAXP = MAXN * lb;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

pii a[MAXN];

struct Data
{
	int l,r;
	Data(void){}
	Data(int _l,int _r): l(_l), r(_r) {}
	inline bool empty(void) const { return l > r;}
	inline bool operator ! (void) const { return empty();}
	vector<Data> getch(int k)
	{
		int mid = l;
		while(mid<=r && bdig(a[mid].first, k) == 0) ++mid;
		return {Data(l, mid-1), Data(mid, r)};
	}
};

int d;
int get1(Data u)
{
	return a[u.l].second;
}
vector<int> get2(Data u,Data v)
{
	if(!u && !v) return {};
	if(!u) return {get1(v)};
	if(!v) return {get1(u)};
	return {get1(u), get1(v)};
}
vector<int> dfs2(Data u,Data v,int dep)
{
	if(!u || !v || dep==-1) return get2(u, v);
	auto chu = u.getch(dep);
	auto chv = v.getch(dep);
	
	vector<int> res;
	auto chk = [&] (const vector<int> &vec)
	{
		if(vec.size() > res.size())
			res = vec;
	};
	
	if(bdig(d, dep) == 1)
	{
		chk(dfs2(chu[0], chv[1], dep-1));
		chk(dfs2(chu[1], chv[0], dep-1));
	}
	else
	{
		chk(dfs2(chu[0], chv[0], dep-1));
		chk(dfs2(chu[1], chv[1], dep-1));
		chk(get2(chu[0], chv[1]));
		chk(get2(chu[1], chv[0]));
	}
	return res;
}
vector<int> dfs(Data u,int dep)
{
	if(!u) return {};
	if(dep == -1)
	{
		vector<int> res;
		for(int i=u.l; i<=u.r; ++i)
			res.push_back(a[i].second);
		return res;
	}
	auto ch = u.getch(dep);
	if(bdig(d, dep) == 0)
	{
		vector<int> l = dfs(ch[0], dep-1), r = dfs(ch[1], dep-1);
		l.insert(l.end(), r.begin(), r.end());
		return l;
	}
	else
	{
		vector<int> res;
		auto chk = [&] (const vector<int> &vec)
		{
			if(vec.size() > res.size())
				res = vec;
		};
		chk(dfs2(ch[0], ch[1], dep-1));
		chk(dfs2(ch[1], ch[0], dep-1));
		return res;
	}
}

int main(void)
{
	int n;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i].first), a[i].second = i;
	
	sort(a+1,a+n+1);
	
	
	auto ans = dfs(Data(1, n), lb-1);
	if(ans.size() <= 1) printf("-1");
	else
	{
		printf("%d\n",(int)ans.size());
		for(int x: ans) printf("%d ",x);
	}
	return 0;
}