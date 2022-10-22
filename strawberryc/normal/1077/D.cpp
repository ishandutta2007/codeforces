#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)

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

const int N = 2e5 + 5;

int n, k, s[N], cnt[N], m;

bool check(int mid)
{
	int i, sum = 0;
	For (i, 1, m)
	{
		sum += cnt[i] / mid;
		if (sum >= k) return 1;
	}
	return 0;
}

void output(int mid)
{
	int i, j, sum = 0;
	For (i, 1, m)
	{
		int st = sum + 1; sum += cnt[i] / mid;
		For (j, st, Min(sum, k)) printf("%d ", i);
		if (sum >= k) return;
	}
}

int main()
{
	int i;
	n = read(); k = read();
	For (i, 1, n)
	{
		s[i] = read();
		m = Max(m, s[i]);
		cnt[s[i]]++;
	}
	int l = 1, r = n;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	output(r);
	std::cout << std::endl;
	return 0;
}