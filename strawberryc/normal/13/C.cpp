#include <cmath>
#include <queue>
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

typedef long long s64;

const int N = 5e5 + 5;

int n, a[N];
s64 ans;

std::priority_queue<int> pq;

int main()
{
	int i;
	n = read();
	For (i, 1, n) a[i] = read();
	For (i, 1, n)
	{
		pq.push(a[i]);
		if (a[i] < pq.top())
		{
			ans += pq.top() - a[i];
			pq.pop(); pq.push(a[i]);
		}
	}
	std::cout << ans << std::endl;
	return 0;
}