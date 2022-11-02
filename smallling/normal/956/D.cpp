#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int gcd(int a, int b)
{
	if(!b)return a;
	if(a % b == 0)return b;
	return gcd(b, a % b);
}

struct num{
	int x, y;
	
	void work()
	{
		int o = gcd(x, y);
		x /= o;
		y /= o;
	}
	
	bool operator ==(const num &b)
	{
		return (x == b.x) && (y == b.y);
	}
}X[N << 1];

struct lhy{
	num l, r;
	int tap;
}e[N << 1];

int n, w, tot, c[N << 1];
long long ans;

int Comp(const num &a, const num &b)
{
	long long x = 1ll * a.x * b.y, y = 1ll * a.y * b.x;
	if(x == y)return 0;
	if(x < y)return 1;
	return -1;
}

inline int cmp(const lhy &a, const lhy &b)
{
	int flag = Comp(a.r, b.r);
	if(flag != 0)
	{
		if(flag == 1)return 1;
		return 0;
	}
	else
	{
		flag = Comp(a.l, b.l);
		if(flag == -1)return 1;
		return 0;
	}
}

inline int cmp1(const lhy &a, const lhy &b)
{
	int flag = Comp(a.l, b.l);
	if(flag != 0)
	{
		if(flag == 1)return 1;
		return 0;
	}
	else
	{
		flag = Comp(a.r, b.r);
		if(flag == 1)return 1;
		return 0;
	}
}

inline int Cmp(const num &a, const num &b)
{
	int flag = Comp(a, b);
	if(flag == 1)return 1;
	return 0;
}

int ask(int x)
{
	int nowans = 0;
	for(; x; x -= x & -x)nowans += c[x];
	return nowans;
}

void add(int x)
{
	for(; x <= tot; x += x & -x)c[x]++;
}

void work1(int tap)
{
	memset(c, 0, sizeof(c));
	for(int i = 1; i <= n; i++)
	{
		if(e[i].tap != tap)continue;
		int l = lower_bound(X + 1, X + 1 + tot, e[i].l, Cmp) - X;
		int r = lower_bound(X + 1, X + 1 + tot, e[i].r, Cmp) - X;
		ans += ask(r) - ask(l - 1);
		add(l);
	}
}

void work2(int tap)
{
	memset(c, 0, sizeof(c));
	for(int i = 1; i <= n; i++)
	{
		int l = lower_bound(X + 1, X + 1 + tot, e[i].l, Cmp) - X;
		int r = lower_bound(X + 1, X + 1 + tot, e[i].r, Cmp) - X;
		if(e[i].tap == tap)ans += ask(r) - ask(l - 1);
		else add(r);
	}
}

int main()
{
	scanf("%d%d", &n, &w);
	for(int i = 1; i <= n; i++)
	{
		int x, v;
		scanf("%d%d", &x, &v);
		int x_ = x; 
		x = abs(x), v = abs(v);
		e[i].l = (num){x, v + w};
		e[i].r = (num){x, v - w};
		e[i].l.work();
		e[i].r.work();
		if(x_ > 0)e[i].tap = 1;
		else e[i].tap = -1;
		X[++tot] = (num){x, v + w};
		X[++tot] = (num){x, v - w};
	}
	sort(e + 1, e + 1 + n, cmp);
	sort(X + 1, X + 1 + tot, Cmp);
	tot = unique(X + 1, X + 1 + tot) - X - 1;
	work1(1);
	work1(-1);
	work2(1);
	work2(-1);
	cout << ans << endl;
}