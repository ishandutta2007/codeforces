#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <sstream>
#include <algorithm>
#include <math.h>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,b,a) for(int (i)=(b)-1;(i)>=(a);--(i))
#define SZ(a) (int)a.size()
#define MP make_pair
#define PB push_back

typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int MAX = 100074;

struct Fenwick
{
	int n;
	int * T;
	Fenwick() {}
	Fenwick(int len)
	{
		n = len;
		T = new int[len];
	}
	void clear()
	{
		FOR(i, 0, n)
			T[i] = 0;
	}
	void add(int pos, int d)
	{
		for (; pos < n; pos = (pos | (pos + 1)))
		{
			T[pos] += d;
		}
	}
	int sum(int r)
	{
		if (r < 0)
			return 0;
		int res = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			res += T[r];
		return res;
	}
	int sum(int l, int r)
	{
		if (l > r)
			return 0;
		return sum(r) - sum(l - 1);
	}
};

struct query
{
	int t;
	int c;
	int l, r, pos;
	string s;
};

int n, m;
char buf[MAX];
int S[MAX];
int CurS[MAX];
query Q[MAX];
Fenwick F[11];
int Res[MAX];

int getId(char c)
{
	if (c == 'A')
		return 0;
	if (c == 'T')
		return 1;
	if (c == 'G')
		return 2;
	return 3;
}

int main()
{
	//freopen("in.txt", "r", stdin);

	scanf("%s", buf);
	n = strlen(buf);
	FOR(i, 0, n)
		S[i] = getId(buf[i]);

	cin >> m;
	FOR(i, 0, m)
	{
		query q;
		int t;
		scanf("%d", &t);
		q.t = t;
		if (t == 1)
		{
			char s[4];
			int pos;
			scanf("%d %s", &pos, s);
			--pos;
			q.pos = pos;
			q.c = getId(s[0]);
		}
		else
		{
			char s[12];
			int l, r;
			scanf("%d %d %s", &l, &r, s);
			--l;
			--r;
			q.l = l;
			q.r = r;
			q.s = s;
			FOR(j, 0, SZ(q.s))
				q.s[j] = '0' + getId(q.s[j]);
		}
		Q[i] = q;
	}

	FOR(i, 0, 10)
		F[i] = Fenwick(n);

	FOR(c, 0, 4)
	FOR(len, 1, 11)
	{
		FOR(i, 0, len)
			F[i].clear();
		FOR(i, 0, n)
		{
			CurS[i] = S[i];
			if (S[i] == c)
			{
				int st = i % len;
				int id = i;
				F[st].add(id, 1);
			}
		}
		FOR(i, 0, m)
		{
			if (Q[i].t == 1)
			{
				if (CurS[Q[i].pos] == Q[i].c)
					continue;

				int prev = CurS[Q[i].pos];
				if (prev == c)
				{
					int st = Q[i].pos % len;
					int id = Q[i].pos;

					F[st].add(id, -1);
				}

				CurS[Q[i].pos] = Q[i].c;
				if (Q[i].c == c)
				{
					int st = Q[i].pos % len;
					int id = Q[i].pos;

					F[st].add(id, 1);
				}
			}
			else
			{
				int sz = SZ(Q[i].s);
				if (sz != len)
					continue;
				FOR(pos, 0, SZ(Q[i].s))
				{
					int st = (Q[i].l + pos) % len;
					if (Q[i].s[pos] - '0' != c)
						continue;
					int ll = Q[i].l;
					int rr = Q[i].r;
					//cout << '+' << endl;
					//cout << st << endl;
					Res[i] += F[st].sum(ll, rr);
					//cout << '-' << endl;
				}
			}
		}
	}

	FOR(i, 0, m)
		if (Q[i].t == 2)
			printf("%d\n", Res[i]);

	return 0;
}