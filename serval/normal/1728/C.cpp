#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

const int N = 2e5 + 5;

int n;

struct Heap
{
	priority_queue <int> q, d;
	void ins(int v)
	{
		q.push(v);
	}
	void del(int v)
	{
		d.push(v);
	}
	void maintain()
	{
		while (!q.empty() && !d.empty() && q.top() == d.top())
		{
			q.pop();
			d.pop();
		}
	}
	int top()
	{
		maintain();
		return q.top();
	}
	void pop()
	{
		del(top());
	}
	bool empty()
	{
		maintain();
		return q.empty();
	}
};

Heap va, vb;
multiset <int> a, b;
int ans;

int f(int v)
{
	int r = 0;
	while (v)
	{
		r++;
		v /= 10;
	}
	return r;
}

void solve()
{
	scanf("%d", &n);
	ans = 0;
	a.clear();
	b.clear();
	for (int i = 1; i <= n; i++)
	{
		int v;
		scanf("%d", &v);
		a.insert(v);
	}
	for (int i = 1; i <= n; i++)
	{
		int v;
		scanf("%d", &v);
		if (a.count(v))
		{
			auto it = a.find(v);
			a.erase(it);
			continue;
		}
		b.insert(v);
	}
	for (auto v : a)
	{
		if (v >= 10)
		{
			va.ins(f(v));
			ans++;
		}
		else
			va.ins(v);
	}
	for (auto v : b)
	{
		if (v >= 10)
		{
			vb.ins(f(v));
			ans++;
		}
		else
			vb.ins(v);
	}
	while (!vb.empty())
	{
		while (va.top() != vb.top())
		{
			ans++;
			if (va.top() > vb.top())
			{
				int v = va.top();
				va.del(v);
				va.ins(f(v));
			}
			else
			{
				int v = vb.top();
				vb.del(v);
				vb.ins(f(v));
			}
		}
		va.pop();
		vb.pop();
	}
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}