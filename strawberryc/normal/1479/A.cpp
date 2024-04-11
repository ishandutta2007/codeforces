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

int px, py, pz;

int query(int x)
{
	printf("? %d\n", x); fflush(stdout);
	scanf("%d", &x); return x;
}

int n;

bool is_valley(int x)
{
	px = query(x), py = 999999, pz = 999999;
	if (x > 1) py = query(x - 1);
	if (x < n) pz = query(x + 1);
	return py > px && px < pz;
}

void orz(int l, int r)
{
	int mid = l + r >> 1;
	if (is_valley(mid)) {printf("! %d\n", mid); fflush(stdout); exit(0);}
	if (l < mid && py < px) orz(l, mid - 1);
	else orz(mid + 1, r);
}

int main()
{
	std::cin >> n; orz(1, n);
	return 0;
}