#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a, b, q;

inline int abs(int x)
{
	return x > 0 ? x : -x;
}

int query(int b1, int f1, int b2, int f2)
{
	if(b1 > b2) swap(b1, b2);
	if(f1 > f2) swap(f1, f2);
	if(b1 == b2) return f2 - f1;
	int res = b2 - b1;
	int cur = f1;
	if(f1 > b)
	{
		res += f1 - b;
		cur = b;
	}
	else if(f1 < a)
	{
		res += a - f1;
		cur = a;
	}
	res += abs(cur - f2);
	return res;
}

int main()
{
	int b1, f1, b2, f2;
	scanf("%d%d%d%d%d", &n, &m, &a, &b, &q);
	for(int i=0; i<q; ++i)
	{
		scanf("%d%d%d%d", &b1, &f1, &b2, &f2);
		printf("%d\n", query(b1, f1, b2, f2));
	}
	
	return 0;
}