#include <set>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 300001;
int n, a[maxn], ans;
vector<int> e[maxn];
multiset<int> sp;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a + i);
		sp.insert(a[i]);
	}
	for(int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ans = ~0u >> 1;
	for(int i = 1; i <= n; ++i)
	{
		int tp = a[i];
		sp.erase(sp.find(a[i]));
		for(vector<int>::iterator it = e[i].begin(); it != e[i].end(); ++it)
		{
			int j = *it;
			sp.erase(sp.find(a[j]));
			if(tp < a[j] + 1)
				tp = a[j] + 1;
		}
		if(sp.size() > 0)
		{
			int v = *sp.rbegin();
			if(tp < v + 2)
				tp = v + 2;
		}
		if(tp < ans)
			ans = tp;
		sp.insert(a[i]);
		for(vector<int>::iterator it = e[i].begin(); it != e[i].end(); ++it)
			sp.insert(a[*it]);
	}
	printf("%d\n", ans);
	return 0;
}