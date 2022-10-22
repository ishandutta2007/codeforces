#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#define null NULL

using namespace std;

typedef long long int64;

struct nd
{
	int x;
	vector<nd*> r;
	nd(int x, int sz)
		:x(x), r(sz)
	{}
	nd(){}
};
int SZ = 30;
int genlev()
{
	int x = 1;
	while (x <= SZ && (rand() & 1))
		++x;
	return x;
}

void _insert(nd* n, int x, int lev)
{
	nd* nw = new nd(x, lev);
	for (int i = SZ - 1; i >= 0; --i)
	{
		while (n->r[i] && n->r[i]->x < x)
			n = n->r[i];
		if (i < lev)
			nw->r[i] = n->r[i], n->r[i] = nw;
	}
}

void _erase(nd* n, int x)
{
	for (int i = SZ - 1; i >= 0; --i)
	{
		while (n->r[i] && n->r[i]->x < x)
			n = n->r[i];
		if (n->r[i] && n->r[i]->x == x)
			n->r[i] = n->r[i]->r[i];
	}
}

nd* lb(nd* n, int x)
{
	for (int i = SZ - 1; i >= 0; --i)
	{
		while (n->r[i] && n->r[i]->x < x)
			n = n->r[i];
	}
	return n->r[0];
}

nd* ll(nd* n, int x)
{
	for (int i = SZ - 1; i >= 0; --i)
	{
		while (n->r[i] && n->r[i]->x < x)
			n = n->r[i];
	}
	return n;
}

nd* insert(nd* sl, int x)
{
	if (!sl)
		sl = new nd(x, SZ);
	else
	{
		int lv = genlev();
		_insert(sl, x, lv);
	}
	return sl;
}

nd* erase(nd* sl, int x)
{
	if (sl->x == x)
	{
		nd* sl1 = sl->r[0];
		int sz1 = sl1->r.size();
		sl1->r.resize(SZ);
		for (int i = SZ - 1; i >= sz1; --i)
			sl1->r[i] = sl->r[i];
		return sl1;
	}
	_erase(sl, x);
	return sl;
}
int main()
{
	int n, k, a;
	scanf("%d %d %d", &n, &k, &a);
	nd* s = null;
	s = insert(s, 0);
	s = insert(s, n + 1);
	int cnt = (n + 1) / (a + 1);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int q;
		scanf("%d", &q);
		auto it1 = ll(s, q);
		auto it = it1->r[0];
		cnt -= (it->x - it1->x) / (a + 1);
		cnt += (q - it1->x) / (a + 1);
		cnt += (it->x - q) / (a + 1);
		s = insert(s, q);
		if (cnt < k)
		{
			cout << i + 1;
			return 0;
		}
	}
	cout << -1;
	return 0;
}

int main1()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	nd* sl = null;
	string s;
	while (cin >> s)
	{
		if (s[0] == 'p')
		{
			if (!sl)
				cout << "null" << endl;
			else
			{
				nd* n = sl;
				while (n)
					cout << n->x << ' ', n = n->r[0];
				cout << endl;
			}
		}
		else if (s[0] == 'i')
		{
			int x; cin >> x;
			sl = insert(sl, x);
		}
		else if (s[0] == 'e')
		{
			int x; cin >> x;
			sl = erase(sl, x);
		}
	}
	return 0;
}