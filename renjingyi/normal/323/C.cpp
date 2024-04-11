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
const int maxn = 1e6 + 5, size = 3.5e7 + 5;
struct Node
{
	int s;
	int lch, rch;
	Node() : s(0), lch(0), rch(0) {}
	Node(const int &s, const int &lch, const int &rch) : s(s), lch(lch), rch(rch) {}
}node[size];
int cnt = 0;
int nNode(const int &s, const int &lch, const int &rch)
{
	node[++ cnt] = Node(s, lch, rch);
	return cnt;
}
int root[maxn];
int set_tree(const int &st, const int &ed)
{
	if(st == ed)
		return nNode(0, 0, 0);
	int mid = st + ed >> 1;
	return nNode(0, set_tree(st, mid), set_tree(mid + 1, ed));
}
int add(const int &r, const int &st, const int &ed, const int &x)
{
	if(st == ed)
		return nNode(node[r].s + 1, 0, 0);
	int mid = st + ed >> 1;
	int t;
	if(x <= mid)
		t = nNode(0, add(node[r].lch, st, mid, x), node[r].rch);
	else
		t = nNode(0, node[r].lch, add(node[r].rch, mid + 1, ed, x));
	node[t].s = node[node[t].lch].s + node[node[t].rch].s;
	return t;
}
int query(const int &r, const int &st, const int &ed, const int &x, const int &y)
{
	if(x <= st && y >= ed)
		return node[r].s;
	int mid = st + ed >> 1;
	int ans = 0;
	if(x <= mid)
		ans += query(node[r].lch, st, mid, x, y);
	if(y > mid)
		ans += query(node[r].rch, mid + 1, ed, x, y);
	return ans;
}
int pos[maxn];
int main()
{
	using namespace Input;
	std::ios::sync_with_stdio(false);
	int n;
	inputnum(n);
	for(int i = 1; i <= n; i ++)
	{
		int x;
		inputnum(x);
		pos[x] = i;
	}
	root[0] = set_tree(1, n);
	for(int i = 1; i <= n; i ++)
	{
		int x;
		inputnum(x);
		root[i] = add(root[i - 1], 1, n, pos[x]);
	}
	int lastans = -1;
	int m;
	inputnum(m);
	for(int i = 1; i <= m; i ++)
	{
		int a, b, c, d;
		inputnum(a);
		inputnum(b);
		inputnum(c);
		inputnum(d);
		int x = lastans + 1;
		int l1 = (a - 1 + x) % n + 1, r1 = (b - 1 + x) % n + 1, l2 = (c - 1 + x) % n + 1, r2 = (d - 1 + x) % n + 1;
		if(l1 > r1)
			swap(l1, r1);
		if(l2 > r2)
			swap(l2, r2);
		printf("%d\n", (lastans = query(root[r2], 1, n, l1, r1) - query(root[l2 - 1], 1, n, l1, r1)));
	}
	
	return 0;
}