#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <vector>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for(int a = 0; a < (b); a++)
#define iter(a) typeof(a.begin())
#define foreach(a, it) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

using namespace std;

const long double EPS = 1e-8;
const int INF = 1000000001;
const int MAXN = 1000001;
const int MAXTSIZE = 2097152;
struct _tree{
	int max;
};
struct light{
	int x, y;
};
bool operator < (light a, light b)
{
	return a.x < b.x;
}

int n;
light a[MAXN];
int ans[MAXN];
_tree t[MAXTSIZE];
/*
void push(int v)
{
	if (v >= MAXTSIZE / 2 - 1) {t[v].d = 0;return;}
	t[2 * v + 1].d += t[v].d;
	t[2 * v + 1].min += t[v].d;
	t[2 * v + 2].d += t[v].d;
	t[2 * v + 2].min += t[v].d;
	t[v].d = 0;
	return;
}
*/

int get(int v, int l, int r, int lx, int rx)
{
	if (l > rx || r < lx) return 0;
//	if (t[v].d != 0) push(v);
	if (lx <= l && r <= rx)
	{
		//_min = t[v].min;
		//mini = t[v].mini;
		return t[v].max;
	}
	int w = get(2 * v + 1, l, (r + l) / 2, lx, rx);

//	int tmin, tmini;
	w = max(w, get(2 * v + 2, (r + l) / 2 + 1, r, lx, rx));
	return w;
}



void add(int v, int l, int r, int p, int d)
{
	if (l > p || r < p) return;
//	if (t[v].d != 0) push(v);
	if (p <= l && r <= p)
	{
	//	t[v].d = d;
		t[v].max += d;
		return;
	}
	add(2 * v + 1, l, (r + l) / 2, p, d);
	t[v].max = t[2 * v + 1].max;
	add(2 * v + 2, (r + l) / 2 + 1, r, p, d);
	if (t[2 * v + 2].max > t[v].max)
	{
		t[v].max = t[2 * v + 2].max;
	}
	return;
}
int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	scanf("%d", &n);
	FOR(i, n)
	{
		int w;
		scanf("%d", &w);
		w--;
		a[w].x = i;
	}
	FOR(i, n)
	{
		int w;
		scanf("%d", &w);
		w--;
		a[w].y = i;
	}

	sort(a, a + n);
	int ans = 0;
	FOR(i, MAXTSIZE) t[i].max = 0;
	FOR(i, n)
	{
		int mx = get(0, 0, MAXTSIZE / 2 - 1, a[i].y, n - 1);
		add(0, 0, MAXTSIZE / 2 - 1, a[i].y, mx + 1);
		ans = max(ans, mx + 1);
	}
	printf("%d", ans);

	return 0;
}