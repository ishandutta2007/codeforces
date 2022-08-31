#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define maxn 200005
#define iter multiset<int>::iterator
using namespace std;
multiset<int> b[maxn];
map<int, int> id;
int num[maxn], tr[maxn];
int tp[maxn], x[maxn], y[maxn];
int idcnt = 1;
int cnt;
struct ST
{
	ST *ch[2];
	int l, r;
	int mxs;
}p[maxn << 1], *root;
int stcnt = 0;
void bdtree(ST *a, int l, int r)
{
	a->l = l, a->r = r, a->mxs = 0;
	if(l == r) return;
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], 
	a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), 
	bdtree(a->ch[1], mid + 1, r);
}
void upd(ST *a)
{
	a->mxs = max(a->ch[0]->mxs, a->ch[1]->mxs);
}
void ch(ST *a, int pl, int num)
{
	if(a->l == a->r)
	{
		a->mxs = num;
		return;
	}
	int mid = (a->l + a->r) >> 1;
	if(pl <= mid) ch(a->ch[0], pl, num);
	else ch(a->ch[1], pl, num);
	upd(a);
}
ST *ns[maxn];
int ncnt; 
void q(ST *a, int l, int r)
{
	if(a->l == l && a->r == r)
	{
		ns[ncnt++] = a;
		return;
	}
	int mid = (a->l + a->r) >> 1;
	if(r <= mid) q(a->ch[0], l, r);
	else if(l > mid) q(a->ch[1], l, r);
	else q(a->ch[0], l, mid), q(a->ch[1], mid + 1, r);
} 
int q(ST *a, int mxs)
{
	if(a->l == a->r) return a->l;
	if(a->ch[0]->mxs >= mxs) return q(a->ch[0], mxs);
	return q(a->ch[1], mxs);
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		char inp[20];
		scanf("%s", inp);
		scanf("%d%d", &x[i], &y[i]);
		if(inp[0] == 'a')
			tp[i] = 0;
		else if(inp[0] == 'r')
			tp[i] = 1;
		else
			x[i]++, y[i]++, 
			tp[i] = 2;
		num[cnt++] = x[i];
	}
	sort(num, num + cnt);
	for(int i = 0; i < cnt; i++)
		if(i == 0 || num[i] != num[i - 1])
			id[num[i]] = idcnt, 
			tr[idcnt] = num[i], 
			idcnt++;
	root = &p[stcnt++];
	bdtree(root, 1, idcnt - 1);
	for(int i = 0; i < n; i++)
	{
		x[i] = id[x[i]];
		if(tp[i] == 0)
			b[x[i]].insert(y[i]);
		else if(tp[i] == 1)
			b[x[i]].erase(b[x[i]].find(y[i]));
		else 
		{
			int l = x[i], r = idcnt - 1;
			ncnt = 0;
			q(root, l, r);
			l = -1;
			for(int j = 0; j < ncnt; j++)
				if(ns[j]->mxs >= y[i])
				{
					l = q(ns[j], y[i]);
					break;
				}
			if(l == -1) printf("-1\n");
			else
			{
				iter n1 = b[l].lower_bound(y[i]);
				printf("%d %d\n", tr[l], *n1);
			}
		}
		if(tp[i] <= 1)
		{
			if(b[x[i]].empty()) ch(root, x[i], 0);
			else 
			{
				iter n1 = b[x[i]].end();
				n1--;
				ch(root, x[i], *n1);
			}
		}
	}
	return 0;	
}