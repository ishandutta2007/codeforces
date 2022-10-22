#include <bits/stdc++.h>

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

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 3e5 + 5;

int n, m, a[N], ans;

bool check(int mid)
{
	int lst = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] + mid < m)
		{
			if (a[i] + mid < lst) return 0;
			lst = Max(lst, a[i]);
		}
		else if (lst > (a[i] + mid) % m)
			lst = Max(lst, a[i]);
	return 1;
}

int main()
{
	n = read(); m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	int l = 0, r = m - 1;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	std::cout << l << std::endl;
	return 0;
}