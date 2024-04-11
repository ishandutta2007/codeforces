#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int maxn = 5e5 + 5;
inline int max(int a, int b)
{
	return a > b ? a : b;
}
namespace BIT
{
	#define lowbit(x) (x & -x)
	int c[maxn];
	void add(const int &p, const int &n, const int &v)
	{
		for(int i = p; i <= n; i += lowbit(i))
			c[i] += v;
	}
	int query(const int &p)
	{
		int ans = 0;
		for(int i = p; i; i -= lowbit(i))
			ans += c[i];
		return ans;
	}
}
namespace LZH
{
	int h[maxn << 2];
	int sum;
	void init(const int &n)
	{
		for(sum = 1; sum < n + 2; sum <<= 1);
	}
	void change(const int &p, const int &v)
	{
		h[sum + p] = v;
		for(int i = sum + p >> 1; i; i >>= 1)
			h[i] = max(h[i << 1], h[i << 1 | 1]);
	}
	int query(const int &l, const int &r)
	{
		int ans = -1e9;
		for(int s = l + sum - 1, t = r + sum + 1; s ^ t ^ 1; s >>= 1, t >>= 1)
		{
			if(~s & 1)
				ans = max(ans, h[s ^ 1]);
			if(t & 1)
				ans = max(ans, h[t ^ 1]);
		}
		return ans;
	}
}
namespace SAM
{
	const int SAM_size = 2;
	typedef struct Node
	{
		int mxl, r;
		Node *next[SAM_size], *fail;
		Node() : mxl(0), r(0), next(), fail(0) {}
	}*pnode;
	Node node[maxn << 1];
	int cnt = 0;
	pnode nNode(const int &mxl = 0)
	{
		cnt ++;
		node[cnt].mxl = mxl;
		return &node[cnt];
	}
	pnode start, last;
	void extend(const int &c, const int &r)
	{
		pnode u = nNode(last->mxl + 1), v = last;
		u->r = r;
		for(; v && !v->next[c]; v = v->fail)
			v->next[c] = u;
		if(!v)
			u->fail = start;
		else if(v->next[c]->mxl == v->mxl + 1)
			u->fail = v->next[c];
		else
		{
			pnode n = nNode(v->mxl + 1), o = v->next[c];
			n->r = o->r;
			copy(o->next, o->next + SAM_size, n->next);
			n->fail = o->fail;
			o->fail = u->fail = n;
			for(; v && v->next[c] == o; v = v->fail)
				v->next[c] = n;
		}
		last = u;
	}
}
vector<int> appear[maxn];
int q[maxn], pos[maxn << 1];
int to[maxn];
bool mark[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	LZH::init(n);
	string s;
	cin >> s;
	SAM::start = SAM::last = SAM::nNode();
	for(int i = 0; i < s.size(); i ++)
		SAM::extend(s[i] == '(' ? 0 : 1, i + 1);
	for(int i = 2; i <= SAM::cnt; i ++)
		appear[SAM::node[i].r].push_back(i);
	memset(pos, -1, sizeof(pos));
	pos[n] = 0;
	for(int i = 1; i <= s.size(); i ++)
	{
		q[i] = q[i - 1] + (s[i - 1] == ')' ? 1 : -1);
		int now = q[i] + n;
		if(pos[now] >= 0)
			to[i] = LZH::query(pos[now] + 1, i - 1) < q[i] ? pos[now] : -1;
		else
			to[i] = -1;
		LZH::change(i, q[i]);
		pos[now] = i;
	}
	long long ans = 0;
	for(int i = n; i >= 1; i --)
		if(!mark[i])
		{
			int x = i;
			while(x && to[x] >= 0)
			{
				BIT::add(to[x] + 1, n, 1);
				x = to[x];
			}
			x = i;
			while(x && to[x] >= 0)
			{
				for(int j = 0; j < appear[x].size(); j ++)
				{
					int now = appear[x][j];
					ans += BIT::query(SAM::node[now].r - SAM::node[now].fail->mxl) - BIT::query(SAM::node[now].r - SAM::node[now].mxl);
				}
				x = to[x];
			}
			x = i;
			while(x && to[x] >= 0)
			{
				BIT::add(to[x] + 1, n, -1);
				mark[x] = 1;
				x = to[x];
			}
		}
	cout << ans << endl;
	
	return 0;
}