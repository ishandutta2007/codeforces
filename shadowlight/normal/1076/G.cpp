#include <bits/stdc++.h>

using namespace std;

const int N = 200043;

typedef long long li;

int n, m;
li a[N];
int q;
int f[N * 4];
vector<int> T[4 * N];
vector<int> T2[4 * N];
int mask;
int cur;

vector<int> combine(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(1 << m);
	for(int i = 0; i < (1 << m); i++)
		c[i] = b[a[i]];
	return c;
}

vector<int> init(li x)
{
	vector<int> ans(1 << m);
	for(int i = 0; i < (1 << m); i++)
	{
		if(i != mask || (x & 1) == 0)
			ans[i] = ((i << 1) & mask) ^ 1;
		else
			ans[i] = ((i << 1) & mask);
	}	
	return ans;
}

void upd(int v)
{
	T[v] = combine(T[v * 2 + 2], T[v * 2 + 1]);
	T2[v] = combine(T2[v * 2 + 2], T2[v * 2 + 1]);
}

void build(int v, int l, int r)
{
	if(l == r - 1)
	{
		T[v] = init(a[l]);
		T2[v] = init(a[l] ^ 1);
		return;
	}
	int m = (l + r) >> 1;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m, r);
	upd(v);
}

void push(int v, int l, int r)
{
	if(f[v])
	{
		swap(T[v], T2[v]);
		if(l != r - 1)
		{
			f[v * 2 + 1] ^= 1;
			f[v * 2 + 2] ^= 1;
		}
		f[v] = 0;
	}
}

vector<int> id;

void get(int v, int l, int r, int L, int R)
{
	push(v, l, r);
	if(L >= R)
		return;
	if(l == L && r == R)
	{
		cur = T[v][cur];
	}
	else
	{
		int m = (l + r) >> 1;
		get(v * 2 + 2, m, r, max(L, m), R);
		get(v * 2 + 1, l, m, L, min(R, m));
		upd(v);	
	}
}

void add(int v, int l, int r, int L, int R)
{
	push(v, l, r);
	if(L >= R)
		return;
	if(l == L && r == R)
	{
		f[v] ^= 1;
		push(v, l, r);
		return;
	}
	else
	{
		int m = (l + r) >> 1;
		add(v * 2 + 1, l, m, L, min(R, m));
		add(v * 2 + 2, m, r, max(L, m), R);
		upd(v);
	}
}

int main() 
{ 
	scanf("%d %d %d", &n, &m, &q);
	mask = (1 << m) - 1;
	for(int i = 0; i < (1 << m); i++)
		id.push_back(i);
	for(int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	build(0, 0, n);
	for(int i = 0; i < q; i++)
	{
		int t, l, r;
		scanf("%d %d %d", &t, &l, &r);
		--l;
		if(t == 1)
		{
			li d;
			scanf("%lld", &d);
			if(d & 1)
				add(0, 0, n, l, r);
		}
		else
		{
			cur = mask;
			get(0, 0, n, l, r);
			
			if((cur & 1) == 1)
				puts("1");
			else
				puts("2");
		}
	}
}