#include <bits/stdc++.h>

// 20030830

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

const int N = 2e5 + 5;

//

int n, a[N], wt;
ll ans;

int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read(); wt = a[n] + 1;
	for (int i = n; i >= 1; i--)
	{
		wt--; if (wt < 0) wt = 0;
		wt = Min(wt, a[i]);
		ans += wt;
	}
	std::cout << ans << std::endl;
	return 0;
}