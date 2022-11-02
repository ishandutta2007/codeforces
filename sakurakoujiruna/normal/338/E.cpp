#include <iostream>
#include <algorithm>
using namespace std;

const int N = 150011;

pair <int, int> imerge(int n1, int m1, int n2, int m2)
{
	int t = min(n1, m2);
	n1 -= t;
	m2 -= t;
	return make_pair(n1 + n2, m1 + m2);
}

struct SegTree
{
	int l[N << 2];
	int r[N << 2];
	int need[N << 2];
	int more[N << 2];

	SegTree() { }
	void init(int left, int right, int x = 1)
	{
		l[x] = left;
		r[x] = right;
		need[x] = right - left;
		if(left + 1 != right)
		{
			int mid = (left + right) / 2;
			init(left, mid, 2 * x);
			init(mid, right, 2 * x + 1);
		}
	}
	void change(int pos, int c, int x = 1)
	{
		if(l[x] + 1 == r[x])
		{
			if(c == 1)
			{
				if(need[x] > 0)
					need[x] --;
				else
					more[x] ++;
			}
			else if(c == -1)
			{
				if(more[x] > 0)
					more[x] --;
				else
					need[x] ++;
			}
		}
		else
		{
			int mid = (l[x] + r[x]) / 2;
			if(pos < mid)
				change(pos, c, 2 * x);
			else
				change(pos, c, 2 * x + 1);

			pair <int, int> p = imerge(need[2 * x], more[2 * x], need[2 * x + 1], more[2 * x + 1]);
			need[x] = p.first;
			more[x] = p.second;
		}
	}
	bool query()
	{
		return need[1] == 0;
	}
}st;

int a[N], b[N];
int t[N];
int pre(int t, int h, int n)
{
	int left = 0, right = n + 1;
	while(left + 1 < right)
	{
		int mid = (left + right) / 2;
		if(b[mid] + t >= h)
			left = mid;
		else
			right = mid;
	}
	return left;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, m, h;
	cin >> n >> m >> h;
	for(int i = 1; i <= m; i ++)
		cin >> b[i];
	sort(b + 1, b + m + 1, greater<int>());
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		t[i] = pre(a[i], h, m);
	}
	st.init(1, m + 1);
	for(int i = 1; i <= m; i ++)
		if(t[i] > 0)
			st.change(t[i], 1);

	int ans = st.query();
	for(int i = m + 1; i <= n; i ++)
	{
		if(t[i] > 0)
			st.change(t[i], 1);
		if(t[i - m] > 0)
			st.change(t[i - m], -1);
		ans += st.query();
		//cout << i << ' ' << ans << '\n';
	}
	/*
	for(int i = 1; i <= n; i ++)
		cout << i << ' ' << t[i] << '\n';
	*/
	cout << ans << '\n';
	return 0;
}