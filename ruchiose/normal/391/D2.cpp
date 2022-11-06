#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<set>
#define i64 long long
#define fortodo(i, f, t) for (i = f; i <= t; i++)
using namespace std;

int N, M, i, j, L, R;
int nx[50001], ny[50001], nl[50001];
int wx[50001], wy[50001], wl[50001];

struct Event
{
	int tp; // 0 = ; 1 = 
	int x; //  
	int a1, a2; //  [a1, a2],  [a1] += a2
	// : ->-> 
	Event() {}
	Event(int _tp, int _x, int _a1, int _a2)
	{
		tp = _tp; x = _x;
		a1 = _a1; a2 = _a2;
	}
};

bool cmp(Event a, Event b)
{
	if (a.x != b.x) return (a.x < b.x);
	return (a.tp * a.a2 > b.tp * b.a2);
}

int e0;
Event es[150001];

multiset<int> seq;
int ins(int l, int v)
{
	if (v == -1)
		seq.erase(seq.find(l));
	else
		seq.insert(l);
}

bool qry(int l, int r)
{
	return (seq.lower_bound(l) != seq.upper_bound(r));
}

bool Chk(int Delta)
{
	e0 = 0;
	fortodo(i, 1, N)
		if (nl[i] >= Delta * 2)
			{
				e0++;
				es[e0] = Event(0, nx[i], ny[i] + Delta, ny[i] + nl[i] - Delta);
			}
	fortodo(i, 1, M)
		if (wl[i] >= Delta * 2)
			{
				e0++;
				es[e0] = Event(1, wx[i] + Delta, wy[i], 1);
				e0++;
				es[e0] = Event(1, wx[i] + wl[i] - Delta, wy[i], -1);
			}
	sort(es + 1, es + e0 + 1, cmp);
	seq.clear();
	fortodo(i, 1, e0)
		if (es[i].tp)
			ins(es[i].a1, es[i].a2);
		else
			if (qry(es[i].a1, es[i].a2))
				return true;
	return false;
}

int main()
{
	scanf("%d%d", &N, &M);
	fortodo(i, 1, N) scanf("%d%d%d", &nx[i], &ny[i], &nl[i]);
	fortodo(i, 1, M) scanf("%d%d%d", &wx[i], &wy[i], &wl[i]);
	if (!Chk(0))
		printf("0\n");
	else
		{
			L = 0; R = 100000001;
			while (R - L > 1)
				{
					int Mid = (L + R) / 2;
					if (Chk(Mid))
						L = Mid;
					else
						R = Mid;
				}
			printf("%d\n", L);
		}
}