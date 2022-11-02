#include <iostream>
#include <set>
#include <cstring>
using namespace std;

const int N = 200011;

struct BIT
{
	int b[N];
	BIT() { }
	int lowbit(int x) { return x & (-x); }
	void init()
	{
		memset(b, 0, sizeof(b));
	}
	void change(int pos, int c)
	{
		pos += 2;
		for(int i = pos; i < N; i += lowbit(i))
			b[i] += c;
	}
	int query(int pos)
	{
		pos += 2;
		int res = 0;
		for(int i = pos; i > 0; i -= lowbit(i))
			res += b[i];
		return res;
	}
}bit[2];

int sum[2][N];
multiset <int> orders[2][N];

void update(int d, int c, int i, int a)
{
	bit[i].change(d, -sum[i][d]);
	orders[i][d].insert(c);
	sum[i][d] += c;
	/*
	while(sum[i][d] > a)
	{
		sum[i][d] -= *orders[i][d].rbegin();
		int t = *orders[i][d].rbegin();
		orders[i][d].erase(orders[i][d].find(t));
	}
	//cout << orders[i][d].size() << '\n';
	*/
	if(sum[i][d] > a)
		sum[i][d] = a;
	bit[i].change(d, sum[i][d]);
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, k, a, b, q;
	cin >> n >> k >> b >> a >> q;
	while(q --)
	{
		int t;
		cin >> t;
		if(t == 1)
		{
			int d, c;
			cin >> d >> c;
			update(d, c, 0, a);
			update(d, c, 1, b);
			/*
			cout << "------\n";
			for(int i = 0; i < 2; i ++)
			{
				for(int j = 1; j <= n; j ++)
					cout << bit[i].query(j) - bit[i].query(j - 1) << ' ';
				cout << '\n';
			}
			*/
		}
		else
		{
			int d;
			cin >> d;
			int ans = 0;
			ans += bit[0].query(d - 1);
			ans += bit[1].query(n) - bit[1].query(d + k - 1);
			cout << ans << '\n';
		}
	}
	return 0;
}