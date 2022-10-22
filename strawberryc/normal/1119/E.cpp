#include <bits/stdc++.h>

// 0830

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

typedef long long ll;

const int N = 3e5 + 5;
const ll INF = 1e18;

int n, a[N];
ll ans, cnt;

int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++)
	{
		int tmp = Min(cnt << 1, 1ll * a[i]) >> 1;
		a[i] -= tmp << 1; cnt -= tmp; ans += tmp;
		ans += a[i] / 3; cnt += a[i] % 3;
	}
	std::cout << ans << std::endl;
	return 0;
}