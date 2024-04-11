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

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	int h = Read(), m = Read(), s = Read(), t1 = Read(), t2 = Read();
	if (h == 12)
		h = 0;
	if (t1 == 12)
		t1 = 0;
	if (t2 == 12)
		t2 = 0;
	double x = h + m / 60.0 + s / 3600.0, y = m / 5.0 + s / 300.0, z = s / 5.0;
	if (t1 > t2)
		swap(t1, t2);
	int ret = (x > t1 && x < t2) + (y > t1 && y < t2) + (z > t1 && z < t2);
	if (ret && ret != 3)
		return puts("NO"), 0;
	return puts("YES"), 0;
}