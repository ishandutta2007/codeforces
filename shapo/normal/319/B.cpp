#include <cstdio>
#include <cstdlib>
#include <stack>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

#define maxn 100500

int n;
int a[maxn];

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
	}
	stack < pair < int, int > > mount;
	int ans = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		int cur = a[i], depth = 0;
		while (!mount.empty() && mount.top().first < cur)
		{
			if (depth < mount.top().second)
			{
				depth = mount.top().second;
			}
			else if (depth == mount.top().second)
			{
				depth = mount.top().second + 1;
			}
			else
			{
				++depth;
			}
			mount.pop();
		}
		//fprintf(stderr, "for i : %d %d\n", cur, depth);
		ans = max(ans, depth);
		mount.push(make_pair(cur, depth));
	}
	printf("%d\n", ans);
	return 0;
}