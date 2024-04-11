#include <stdio.h>
#include <iostream>
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
namespace Input
{
	const int BUF = 1048576;
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
}
const int maxn = 5e5 + 5;
typedef struct Node
{
	int s, t, mn, id, mnp;
	bool rev;
	Node *ch[2], *p;
	Node(const int &t = maxn, const int &id = 0) : s(1), t(t), mn(t), id(id), mnp(id), rev(0), ch(), p(0) {}
}*pnode;
pnode point[55][maxn], point2[maxn];
int gets(const pnode &r)
{
	return r ? r->s : 0;
}
int getmn(const pnode &r)
{
	return r ? r->mn : maxn;
}
void update(const pnode &r)
{
	r->s = gets(r->ch[0]) + 1 + gets(r->ch[1]);
	r->mn = r->t;
	r->mnp = r->id;
	if(getmn(r->ch[0]) < r->mn)
	{
		r->mn = r->ch[0]->mn;
		r->mnp = r->ch[0]->mnp;
	}
	if(getmn(r->ch[1]) < r->mn)
	{
		r->mn = r->ch[1]->mn;
		r->mnp = r->ch[1]->mnp;
	}
}
void rev(const pnode &r)
{
	if(!r)
		return;
	swap(r->ch[0], r->ch[1]);
	r->rev ^= 1;
}
void down(const pnode &r)
{
	if(r->rev)
	{
		rev(r->ch[0]);
		rev(r->ch[1]);
		r->rev = 0;
	}
}
bool is_root(const pnode &r)
{
	return !r->p || r != r->p->ch[0] && r != r->p->ch[1];
}
void link(const pnode &p, const pnode &ch, const bool &w)
{
	p->ch[w] = ch;
	if(ch)
		ch->p = p;
	update(p);
}
void rotate(const pnode &p, const bool &w)
{
	pnode r = p->ch[w], pp = p->p;
	bool asd = is_root(p);
	link(p, r->ch[w ^ 1], w);
	link(r, p, w ^ 1);
	if(asd)
		r->p = pp;
	else
		link(pp, r, p == pp->ch[1]);
}
void splay(const pnode &r)
{
	static stack<pnode> st;
	st.push(r);
	for(pnode p = r; !is_root(p); p = p->p)
		st.push(p->p);
	while(!st.empty())
	{
		down(st.top());
		st.pop();
	}
	for(; !is_root(r); rotate(r->p, r == r->p->ch[1]))
		if(!is_root(r->p))
			(r == r->p->ch[1]) == (r->p == r->p->p->ch[1]) ? rotate(r->p->p, r == r->p->ch[1]) : rotate(r->p, r == r->p->ch[1]);
}
void access(const pnode &r)
{
	pnode now = 0, asd = r, st = r;
	while(asd)
	{
		splay(asd);
		link(asd, now, 1);
		now = asd;
		asd = asd->p;
	}
	splay(st);
}
void set_root(const pnode &r)
{
	access(r);
	rev(r);
}
void extract(const pnode &x, const pnode &y)
{
	set_root(x);
	access(y);
}
void link(const pnode &x, const pnode &y)
{
	extract(x, y);
	set_root(x);
	x->p = y;
}
void cut(const pnode &x, const pnode &y)
{
	extract(x, y);
	if(y == x->p && !x->ch[1])
	{
		x->p = y->ch[0] = 0;
		update(y);
	}
}
int a[maxn], b[maxn], c[maxn], x[maxn], to[maxn], pos[maxn];
vector<int> t[maxn];
int main()
{
	using namespace Input;
	std::ios::sync_with_stdio(false);
	int n, m, k, q;
	inputnum(n);
	inputnum(m);
	inputnum(k);
	inputnum(q);
	for(int i = 1; i <= m; i ++)
	{
		inputnum(a[i]);
		inputnum(b[i]);
	}
	for(int i = 1; i <= q; i ++)
	{
		inputnum(x[i]);
		inputnum(to[i]);
		t[x[i]].push_back(i);
	}
	for(int i = 1; i <= m; i ++)
	{
		t[i].push_back(q + 1);
		point2[i] = new Node(t[i][pos[i] ++], i);
	}
	for(int i = 1; i <= q; i ++)
	{
		int p = x[i];
		pnode l = point[to[i]][a[p]], r = point[to[i]][b[p]];
		if(!l)
			l = point[to[i]][a[p]] = new Node;
		if(!r)
			r = point[to[i]][b[p]] = new Node;
		pnode lastl = point[c[p]][a[p]], lastr = point[c[p]][b[p]];
		if(c[p])
		{
			cut(lastl, point2[p]);
			cut(point2[p], lastr);
		}
		point2[p]->t = t[p][pos[p] ++];
		update(point2[p]);
		extract(l, r);
		if(is_root(l))
		{
			link(l, point2[p]);
			link(point2[p], r);
			printf("YES\n");
			c[p] = to[i];
		}
		else if(gets(r) % 4 == 3)
		{
			if(r->mn < point2[p]->t)
			{
				int tmp = r->mnp;
				cut(point[to[i]][a[tmp]], point2[tmp]);
				cut(point2[tmp], point[to[i]][b[tmp]]);
				link(l, point2[p]);
				link(point2[p], r);
			}
			printf("YES\n");
			c[p] = to[i];
		}
		else
		{
			if(c[p])
			{
				extract(lastl, lastr);
				if(is_root(lastl))
				{
					link(lastl, point2[p]);
					link(point2[p], lastr);
				}
				else if(lastr->mn < point2[p]->t)
				{
					int tmp = lastr->mnp;
					cut(point[c[p]][a[tmp]], point2[tmp]);
					cut(point2[tmp], point[c[p]][b[tmp]]);
					link(lastl, point2[p]);
					link(point2[p], lastr);
				}
			}
			printf("NO\n");
		}
	}
	
	return 0;
}