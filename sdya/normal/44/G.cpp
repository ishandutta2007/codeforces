#include <iostream>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

#define MLEN 110000

int n, m;
int xl[MLEN], xr[MLEN], yl[MLEN], yr[MLEN], z[MLEN], num[MLEN];
int x[MLEN], y[MLEN], res[MLEN];

map < int, int > MP;
set < int > S;

//set < pair < int, int > > t[12 * MLEN];
vector < int > t[12 * MLEN];
vector < int > p[12 * MLEN];
vector < int > q[12 * MLEN];

vector < pair < int, int > > start[3 * MLEN + 5];

void compress(int x1[], int x2[], int x3[])
{
	MP.clear(); S.clear();
	for (int i = 1; i <= n; i ++)
		S.insert(x1[i]), S.insert(x2[i]);
	for (int i = 1; i <= m; i ++)
		S.insert(x3[i]);
	int f = 0;
	for (set < int > :: iterator it = S.begin(); it != S.end(); it ++)
		f ++, MP[* it] = f;
	for (int i = 1; i <= n; i ++)
		x1[i] = MP[x1[i]], x2[i] = MP[x2[i]];
	for (int i = 1; i <= m; i ++)
		x3[i] = MP[x3[i]];
}

bool comp(int x, int y)
{
	return z[x] < z[y];
}

void build(vector < int > &a, vector < int > &b, int i, int l, int r)
{
	if (l == r) {b[i] = l; return ;}
	build(a, b, 2 * i, l, (l + r) / 2);
	build(a, b, 2 * i + 1, (l + r) / 2 + 1, r);

	b[i] = a[b[2 * i]] < a[b[2 * i + 1]] ? b[2 * i] : b[2 * i + 1];
}

int getmin(vector < int > &a, vector < int > &b, int i, int cl, int cr, int l, int r)
{
	if (cl == l && cr == r) return a[i];
	if (l > (cl + cr) / 2)
		return getmin(a, b, 2 * i + 1, (cl + cr) / 2 + 1, cr, l, r);
	if (r <= (cl + cr) / 2)
		return getmin(a, b, 2 * i, cl, (cl + cr) / 2, l, r);

	int A = getmin(a, b, 2 * i, cl, (cl + cr) / 2, l, (cl + cr) / 2);
	int B = getmin(a, b, 2 * i + 1, (cl + cr) / 2 + 1, cr, (cl + cr) / 2 + 1, r);
	return b[A] < b[B] ? A : B;
}

void update(vector < int > &a, vector < int > &b, int i, int l, int r, int k)
{
	if (l == r) { return ;}
	if (k > (l + r) / 2)
		update(a, b, 2 * i + 1, (l + r) / 2 + 1, r, k); else
		update(a, b, 2 * i, l, (l + r) / 2, k);
	a[i] = b[a[2 * i]] < b[a[2 * i + 1]] ? a[2 * i] : a[2 * i + 1];
}

/*void build(int i, int l, int r)
{
	if (l == r)
	{
		for (int j = 0; j < start[l].size(); j ++)
			t[i].insert(start[l][j]);
		return ;
	}
	build(i + i, l, (l + r) / 2);
	build(i + i + 1, (l + r) / 2 + 1, r);
	for (set < pair < int, int > > :: iterator it = t[i + i].begin(); it != t[i + i].end(); it ++)
		t[i].insert(* it);
	for (set < pair < int, int > > :: iterator it = t[i + i + 1].begin(); it != t[i + i + 1].end(); it ++)
		t[i].insert(* it);
}*/

void build(int i, int l, int r)
{
	if (l == r)
	{
		t[i].resize(start[l].size());
		p[i].resize(start[l].size());
		sort(start[l].begin(), start[l].end());
		for (int j = 0; j < start[l].size(); j ++)
			t[i][j] = start[l][j].first, p[i][j] = start[l][j].second;

		q[i].resize(4 * start[l].size());
		if (start[l].size() == 0) return ;

		build(p[i], q[i], 1, 0, start[l].size() - 1);
		return ;
	}
	build(2 * i, l, (l + r) / 2);
	build(2 * i + 1, (l + r) / 2 + 1, r);
	int sz = t[2 * i].size() + t[2 * i + 1].size();
	if (sz == 0) return ;
	t[i].resize(sz);
	p[i].resize(sz);
	q[i].resize(4 * sz);
	vector < pair < int, int > > x;
	for (int j = 0; j < t[2 * i].size(); j ++) x.push_back(make_pair(t[2 * i][j], p[2 * i][j]));
	for (int j = 0; j < t[2 * i + 1].size(); j ++) x.push_back(make_pair(t[2 * i + 1][j], p[2 * i + 1][j]));
	sort(x.begin(), x.end());
	for (int j = 0; j < x.size(); j ++)
		t[i][j] = x[j].first, p[i][j] = x[j].second;
	build(p[i], q[i], 1, 0, sz - 1);
}

int least(vector < int > &a, int x)
{
	if (a.size() == 0) return -1;
	int l = 0, r = a.size() - 1;
	while (r - l > 1)
	{
		int key = (l + r) / 2;
		if (a[key] >= x)
			r = key; else
			l = key;
	}
	if (a[l] >= x)
		return l;
	if (a[r] >= x)
		return r;
	return -1;
}

int biggest(vector < int > &a, int x)
{
	if (a.size() == 0) return -1;
	int l = 0, r = a.size() - 1;
	while (r - l > 1)
	{
		int key = (l + r) / 2;
		if (a[key] <= x)
			l = key; else
			r = key;
	}
	if (a[r] <= x)
		return r;
	if (a[l] <= x)
		return l;
	return -1;
}

void del(int i, int l, int r, pair < int, int > kill)
{
	/*if (l == r)
	{
		t[i].erase(kill);
		return ;
	}
	if (t[i].count(kill) == 0) return ;
	t[i].erase(kill);
	del(2 * i, l, (l + r) / 2, kill);
	del(2 * i + 1, (l + r) / 2 + 1, r, kill);*/
	int L = least(t[i], kill.first), R = biggest(t[i], kill.first);
	if (L == -1 || R == -1 || L > R) return ;
	for (int j = L; j <= R; j ++)
		if (p[i][j] == kill.second)
		{
			p[i][j] = 1e9;
			update(q[i], p[i], 1, 0, t[i].size() - 1, j);
			del(2 * i, l, (l + r) / 2, kill);
			del(2 * i + 1, (l + r) / 2 + 1, r, kill);
			return ;
		}
}

void del_up(int i, pair < int, int > kill)
{
	/*if (i == 0 || t[i].count(kill) == 0) return ;
	t[i].erase(kill);
	del_up(i >> 1, kill);*/
	if (i == 0) return ;
	int L = least(t[i], kill.first), R = biggest(t[i], kill.first);
	if (L == -1 || R == -1 || L > R) return ;
	//int v = getmin(q[i], p[i], 1, 0, t[i].size() - 1, L, R);
	for (int j = L; j <= R; j ++)
		if (p[i][j] == kill.second)
		{
			p[i][j] = 1e9;
			update(q[i], p[i], 1, 0, t[i].size() - 1, j);
			del_up(i >> 1, kill);
			return ;
		}
}


pair < int, int > rs;
int level, ll, lr;

/*void update(int i, int l, int r, int xl, int xr, int yl, int yr)
{
	if (l == xl && r == xr)
	{
		set < pair < int, int > > :: iterator it = t[i].lower_bound(make_pair(yl, -1));
		while (it != t[i].end())
		{
			if (it->first > yr) break;
			if (it->second < rs.second) rs = * it, level = i, ll = l, lr = r;
			it ++;
		}
		return ;
	} 
	if (xl > (l + r) / 2) update(2 * i + 1, (l + r) / 2 + 1, r, xl, xr, yl, yr); else
	if (xr <= (l + r) / 2) update(2 * i, l, (l + r) / 2, xl, xr, yl, yr); else
	{
		update(2 * i, l, (l + r) / 2, xl, (l + r) / 2, yl, yr);
		update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, xr, yl, yr);
	}
}*/


void update(int i, int l, int r, int xl, int xr, int yl, int yr)
{
	if (l == xl && r == xr)
	{
		int L = least(t[i], yl), R = biggest(t[i], yr);
		if (L == -1 || R == -1 || L > R) return ;
		int x = getmin(q[i], p[i], 1, 0, p[i].size() - 1, L, R);
		if (p[i][x] < rs.second)
			rs = make_pair(t[i][x], p[i][x]), level = i, ll = l, lr = r;
		return ;
	} 
	if (xl > (l + r) / 2) update(2 * i + 1, (l + r) / 2 + 1, r, xl, xr, yl, yr); else
	if (xr <= (l + r) / 2) update(2 * i, l, (l + r) / 2, xl, xr, yl, yr); else
	{
		update(2 * i, l, (l + r) / 2, xl, (l + r) / 2, yl, yr);
		update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, xr, yl, yr);
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d%d%d%d%d", &xl[i], &xr[i], &yl[i], &yr[i], &z[i]), num[i] = i;
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++)
		scanf("%d%d", &x[i], &y[i]);
	compress(xl, xr, x);
	compress(yl, yr, y);
	sort(num + 1, num + n + 1, comp);
	for (int i = 1; i <= m; i ++)
		start[x[i]].push_back(make_pair(y[i], i));
	int mx = 0;
	for (int i = 1; i <= MLEN; i ++)
		if (start[i].size() != 0) mx = i;
	for (int i = 1; i <= n; i ++)
		mx = max(mx, xr[i]);
	build(1, 1, mx);
	for (int i = 1; i <= n; i ++)
	{
		rs = make_pair(1000000000, 1000000000);
		update(1, 1, mx, xl[num[i]], xr[num[i]], yl[num[i]], yr[num[i]]);
		if (rs.second != 1000000000)
			res[rs.second] = num[i], del_up(level >> 1, rs), del(level, ll, lr, rs);
	}
	for (int i = 1; i <= m; i ++)
		printf("%d\n", res[i]);

	return 0;
}