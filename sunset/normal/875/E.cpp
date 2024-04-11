#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 100005;

int n, a[MAXN];

inline bool Chk(int x)
{
	set <int> s;
	if (abs(a[3] - a[1]) <= x)
		s.insert(a[1]);
	if (abs(a[3] - a[2]) <= x)
		s.insert(a[2]);
	if (s.empty())
		return false;
	for (int i = 4; i <= n; i ++)
	{
		while (!s.empty() && abs(*s.begin() - a[i]) > x)
			s.erase(*s.begin());
		while (!s.empty() && abs(*s.rbegin() - a[i]) > x)
			s.erase(*s.rbegin());
		if (abs(a[i] - a[i - 1]) <= x)
			s.insert(a[i - 1]);
		if (s.empty())
			return false;
	}
	return true;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read() + 2, a[1] = Read(), a[2] = Read();
	for (int i = 3; i <= n; i ++)
		a[i] = Read();
	int l = abs(a[1] - a[2]), r = 0x3f3f3f3f, ret = 0;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (Chk(mid))
			ret = mid, r = mid - 1;
		else
			l = mid + 1;
	}
	return printf("%d\n", ret), 0;
}