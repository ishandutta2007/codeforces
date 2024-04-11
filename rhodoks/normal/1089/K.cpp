#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1; char ch = getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
# define ls (cur << 1)
# define rs (cur << 1 | 1)
typedef long long ll;
const int M = 100016, MOD = 1000000007;
const int MAXN = 1e6 + 5;
struct SGT
{
	int n;
	ll a[MAXN << 2];
	ll tag[MAXN << 2];

	void update(ll val, int cur)
	{
		a[cur] += val;
		tag[cur] += val;
	}

	void push_up(int cur) { a[cur] = max(a[ls], a[rs]); }

	void push_down(int cur)
	{
		update(tag[cur], ls);
		update(tag[cur], rs);
		tag[cur] = 0;
	}

	void build(int left, int right, int cur)
	{
		if (left == right)
		{
			a[cur] = left;
			return;
		}
		int mid = (left + right) >> 1;
		build(left, mid, ls);
		build(mid + 1, right, rs);
		push_up(cur);
	}

	void build(int size)
	{
		n = size;
		build(1, n, 1);
	}

	void update(int x, int y, ll val, int left, int right, int cur)
	{
		if (left >= x && right <= y)
		{
			update(val, cur);
			return;
		}
		if (tag[cur])
			push_down(cur);
		int mid = (left + right) >> 1;
		if (x <= mid)
			update(x, y, val, left, mid, ls);
		if (y > mid)
			update(x, y, val, mid + 1, right, rs);
		push_up(cur);
	}

	ll query(int x, int y, int left, int right, int cur)
	{
		if (left >= x && right <= y)
			return a[cur];
		if (tag[cur])
			push_down(cur);
		int mid = (left + right) >> 1;
		ll ret = 0;
		if (x <= mid)
			ret = max(ret, query(x, y, left, mid, ls));
		if (y > mid)
			ret = max(ret, query(x, y, mid + 1, right, rs));
		return ret;
	}

	void update(int x, int y, ll val) { update(x, y, val, 1, n, 1); }

	ll query(int x, int y) { return query(x, y, 1, n, 1); }
};

struct BIT
{
	int n;
	ll a[MAXN];

	int lowbit(int x) { return x & -x; }

	void build(int size) { n = size; }

	void update(int x, ll val)
	{
		for (; x <= n; x += lowbit(x))
			a[x] += val;
	}

	ll query(int x)
	{
		ll ret = 0;
		for (; x; x -= lowbit(x))
			ret += a[x];
		return ret;
	}

	ll query(int x, int y) { return query(y) - query(x - 1); }
};

SGT s;
BIT b;
pair<ll, ll> v[MAXN];

int main(void)
{
	#ifdef _LITTLEFALL_
	freopen("in.txt","r",stdin);
	#endif
	ll q, x, y;
	char op[3];
	scanf("%lld", &q);
	s.build(1e6);
	b.build(1e6);
	for (int i = 1; i <= q; ++i)
	{
		scanf("%s %lld", op, &x);
		if (op[0] == '?')
			printf("%lld\n", max(0LL, s.query(1, x) - b.query(x + 1, 1e6) - x));
		else if (op[0] == '+')
		{
			scanf("%lld", &y);
			s.update(1, x, y);
			v[i] = {x, y};
			b.update(x, y);
		}
		else
		{
			s.update(1, v[x].first, -v[x].second);
			b.update(v[x].first, -v[x].second);
		}
	}

	return 0;
}