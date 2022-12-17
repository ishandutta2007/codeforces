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
#define mp(a, b) make_pair(a, b)
using namespace std;
namespace Input
{
	const int BUF = 1 << 20;
	char buf[BUF + 1];
	char *head = buf, *tail = buf;
	char inputchar()
	{
		if(head == tail)
			*(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;
		return *head ++;
	}
	void inputnum(int &ret)
	{
		char ch = inputchar();
		while(ch < '0' || ch > '9')
			ch = inputchar();
		ret = ch - '0';
		ch = inputchar();
		while(ch >= '0' && ch <= '9')
		{
			ret = ret * 10 + ch - '0';
			ch = inputchar();
		}
	}
	void inputnum(long long &ret)
	{
		char ch = inputchar();
		while(ch < '0' || ch > '9')
			ch = inputchar();
		ret = ch - '0';
		ch = inputchar();
		while(ch >= '0' && ch <= '9')
		{
			ret = ret * 10 + ch - '0';
			ch = inputchar();
		}
	}
}
typedef pair<long long, int> pp;
const int maxn = 5e5 + 5;
typedef struct Node
{
	int st, ed;
	int s;
	Node *lch, *rch;
}*pnode;
Node node[maxn << 2];
int ttt = 0;
pnode nNode(const int &st, const int &ed, const pnode &lch, const pnode &rch)
{
	ttt ++;
	node[ttt].st = st;
	node[ttt].ed = ed;
	node[ttt].s = 0;
	node[ttt].lch = lch;
	node[ttt].rch = rch;
	return &node[ttt];
}
pnode root = 0;
pnode set_tree(const int &st, const int &ed)
{
	if(st == ed)
		return nNode(st, ed, 0, 0);
	int mid = st + ed >> 1;
	return nNode(st, ed, set_tree(st, mid), set_tree(mid + 1, ed));
}
void update(const pnode &r)
{
	r->s = r->lch->s + r->rch->s;
}
void add(const pnode &r, const int &x)
{
	if(r->st == r->ed)
	{
		r->s ++;
		return;
	}
	if(x <= r->lch->ed)
		add(r->lch, x);
	else
		add(r->rch, x);
	update(r);
}
int query(const pnode &r, const int &v)
{
	if(r->st == r->ed)
		return r->st;
	if(v <= r->lch->s)
		return query(r->lch, v);
	else
		return query(r->rch, v - r->lch->s);
}
pp cnt[maxn], a[maxn];
int ans[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	using namespace Input;
	int n, m, q;
	inputnum(n);
	inputnum(m);
	inputnum(q);
	root = set_tree(1, m);
	for(int i = 1; i <= n; i ++)
	{
		int x;
		inputnum(x);
		cnt[x].first ++;
	}
	for(int i = 1; i <= m; i ++)
		cnt[i].second = i;
	sort(cnt + 1, cnt + m + 1);
	for(int i = 1; i <= q; i ++)
	{
		inputnum(a[i].first);
		a[i].first -= n;
		a[i].second = i;
	}
	sort(a + 1, a + q + 1);
	long long now = 1, pos = cnt[1].first, pre = 0;
	for(; now <= m && cnt[now].first == pos; now ++)
		add(root, cnt[now].second);
	for(int i = 1; i <= q; i ++)
	{
		long long k = a[i].first;
		int id = a[i].second;
		while(now <= m && pre + (cnt[now].first - pos) * (now - 1) < k)
		{
			pre += (cnt[now].first - pos) * (now - 1);
			pos = cnt[now].first;
			for(; now <= m && cnt[now].first == pos; now ++)
				add(root, cnt[now].second);
		}
		int last = (k - pre) % (now - 1);
		ans[id] = query(root, last == 0 ? now - 1 : last);
	}
	for(int i = 1; i <= q; i ++)
		cout << ans[i] << '\n';
	
	return 0;
}