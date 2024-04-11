#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

const int N = 105;

int n, m1, m2, a[N], b[N];

void work()
{
	read(n); read(m1); read(m2);
	for (int i = 1; i <= m1; i++) read(a[i]);
	for (int i = 1; i <= m2; i++) read(b[i]);
	std::sort(a + 1, a + m1 + 1); std::sort(b + 1, b + m2 + 1);
	while (m1 && m2)
		if (a[m1] > b[m2])
		{
			a[++m1] = b[1]; std::sort(a + 1, a + m1 + 1);
			for (int i = 1; i < m2; i++) b[i] = b[i + 1];
			m2--;
		}
		else
		{
			b[++m2] = a[1]; std::sort(b + 1, b + m2 + 1);
			for (int i = 1; i < m1; i++) a[i] = a[i + 1];
			m1--;
		}
	puts(m1 ? "YES" : "NO");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}