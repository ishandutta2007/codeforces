#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1000 + 9;

int n;
int a[MAXN];
bool vis[MAXN];

inline int abs(int x)
{
	return x > 0 ? x : -x;
}

int fun(int start)
{
	memset(vis, 0, sizeof(vis));
	int res;
	for(res = start; !vis[res]; res = a[res]) vis[res] = true;
	return res;
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", &a[i]);
	for(int i=1; i<=n; ++i) printf("%d ", fun(i));
	
	return 0;
}