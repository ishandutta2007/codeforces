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
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

typedef long long ll;

const int N = 3e5 + 5;

int n, a[N], nt = 1, ans;

int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	while (a[1] == a[nt]) nt++;
	for (int i = nt; i <= n; i++)
		if (a[1] != a[i]) ans = Max(ans, i - 1);
		else ans = Max(ans, i - nt);
	std::cout << ans << std::endl;
	return 0;
}