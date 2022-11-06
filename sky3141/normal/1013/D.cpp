#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 200000 + 10;

int n, m, q;
int f[MAXN*2];
int ans;

int getfa(int x)
{
	if(f[x] == x) return x;
	return f[x] = getfa(f[x]);
}

void join(int u, int v)
{
	f[getfa(u)] = getfa(v);
}

inline int row(int x)
{
	return x;
}

inline int col(int y)
{
	return n + y;
}

int main()
{
	int x, y;
	scanf("%d%d%d", &n, &m, &q);
	ans = n + m - 1;
	for(int i=1; i<=n+m; ++i)
		f[i] = i;
	for(int i=0; i<q; ++i)
	{
		scanf("%d%d", &x, &y);
		if(getfa(row(x)) != getfa(col(y)))
		{
			join(row(x), col(y));
			--ans;
		}
	}
	printf("%d", ans);
	
	return 0;
}