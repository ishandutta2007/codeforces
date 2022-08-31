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

inline LL Read()
{
	LL x = 0; int f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

LL ans, lst, cur;
map <LL, LL> a;
int n;

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), lst = Read(), a[lst - 1] = 0;
	for (int i = 1; i < n; i ++)
		if ((cur = Read()) < lst)
			for (auto it = a.lower_bound(lst = cur); it != a.end(); a.erase(it ++))
				a[cur - 1] = max(a[cur - 1], it -> yy + (it -> xx - cur + 1) / cur * cur * i), a[it -> xx % cur] = max(a[it -> xx % cur], it -> yy + it -> xx / cur * cur * i);
	for (auto x : a)
		ans = max(ans, x.xx * n + x.yy);
	cout << ans << endl;
	return 0;
}