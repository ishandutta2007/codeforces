#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> llll;
const int Maxn = 100005;
const int Maxm = 524288;
const ll Inf = 1000000000000000000ll;
struct node {
	ll sum;
	ll besttwo;
	ll bestone;
	bool hashill;
	ll lef, rig;
	node(): sum(0), besttwo(Inf), bestone(Inf), hashill(false), lef(0), rig(0) {}
};

int n;
ll a[Maxn];
node st[Maxm];
int q;

node Union(const node &a, const node &b)
{
	node c;
	c.sum = a.sum + b.sum;
	c.besttwo = min(a.besttwo, b.besttwo);
	c.bestone = min(a.bestone, b.bestone);
	c.hashill = a.hashill || b.hashill;
	c.lef = a.lef; c.rig = b.rig;
	if (a.rig >= 0 && b.lef <= 0) c.hashill = true;
	else if (a.rig < 0 && b.lef > 0) { 
		c.besttwo = min(c.besttwo, -a.rig + b.lef);
	} else c.bestone = min(c.bestone, max(-a.rig, b.lef));
	return c;
}

void Assign(int v, int l)
{
	st[v].sum = abs(a[l]);
	st[v].bestone = st[v].besttwo = Inf;
	st[v].hashill = false;
	st[v].lef = st[v].rig = a[l];
}

void Create(int v, int l, int r)
{
	if (l == r) Assign(v, l);
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		st[v] = Union(st[2 * v], st[2 * v + 1]);
	}
}

void Inc(int v, int l, int r, int x, int val)
{
	if (l == r) { a[l] += val; Assign(v, l); }
	else {
		int m = l + r >> 1;
		if (x <= m) Inc(2 * v, l, m, x, val);
		else Inc(2 * v + 1, m + 1, r, x, val);
		st[v] = Union(st[2 * v], st[2 * v + 1]);
	}
}

node Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		int m = l + r >> 1;
		if (b <= m) return Get(2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
		return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", &a[i]);
		if (i > 1) a[i - 1] = a[i] - a[i - 1];
	}
	Create(1, 1, n - 1);
	scanf("%d", &q);
	while (q--) {
		int typ, l, r, x; scanf("%d %d %d %d", &typ, &l, &r, &x);
		if (typ == 1) {
			ll orig = Get(1, 1, n - 1, 1, n - 1).sum;
			ll best = -Inf;
			if (l == 1) best = max(best, abs(a[1] - x) + Get(1, 1, n - 1, 2, n - 1).sum);
			if (r == n) best = max(best, abs(a[n - 1] + x) + Get(1, 1, n - 1, 1, n - 2).sum);
			int lef = max(1, l - 1), rig = min(n - 1, r);
			node tmp = Get(1, 1, n - 1, lef, rig);
			if (tmp.hashill) best = max(best, orig + 2ll * x);
			if (tmp.bestone <= x) best = max(best, orig + (x - tmp.bestone) * 2ll);
			else if (tmp.bestone < Inf) best = max(best, orig);
			if (tmp.besttwo <= x) best = max(best, orig + (x - tmp.besttwo) * 2ll);
			if (best <= -Inf) {
				orig -= (abs(a[l - 1]) + abs(a[l]));
				orig += (abs(a[l - 1] + x) + abs(a[l] - x));
				best = orig;
			}
			printf("%I64d\n", best);
		} else if (typ == 2) {
			if (l > 1) Inc(1, 1, n - 1, l - 1, x);
			if (r < n) Inc(1, 1, n - 1, r, -x);
		}
	}
}