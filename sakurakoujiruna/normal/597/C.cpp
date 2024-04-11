#include <iostream>
#include <cstring>
using namespace std;

const int N = 101111;
const int M = 12;
typedef long long intl;

int lowbit(int x)
{
	return x & (-x);
}
struct BIT
{
	intl b[N];
	BIT() { init(); }
	void init() { memset(b, 0, sizeof(b)); }
	void change(int pos, intl c)
	{
		pos += 2;
		for(int i = pos; i < N; i += lowbit(i))
			b[i] += c;
	}
	intl query(int pos)
	{
		pos += 2;
		intl ret = 0;
		for(int i = pos; i > 0; i -= lowbit(i))
			ret += b[i];
		return ret;
	}
}bit[M];
int a[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		for(int k = m; k >= 1; k --)
		{
			bit[k].change(a[i], bit[k - 1].query(a[i]));
		}
		bit[0].change(a[i], 1);
	}
	cout << bit[m].query(n) << '\n';
	return 0;
}