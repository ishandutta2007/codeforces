#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int MAXN = 2E5 + 10;

int n;
int p[MAXN], b[MAXN];
int last[MAXN];
vector<int> E[MAXN];

int que[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d%d", p + i, b + i);
		E[p[i]].push_back(i);
	}
	map<int, int> lst;
	for (int i = 1; i <= n; ++i)
		if (!E[i].empty())
			lst[E[i].back()] = i;

	int q;
	scanf("%d", &q);
	while (q--){
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; ++i){
			scanf("%d", que + i);
			if (!E[que[i]].empty())
				lst.erase(E[que[i]].back());
			else
				--i, --m;
		}

		if (lst.empty())
			puts("0 0");
		else{
			int u = lst.rbegin()->second, v = 0;
			if (lst.size() > 1)
				v = (++lst.rbegin())->first;
			printf("%d %d\n", u, b[*upper_bound(E[u].begin(), E[u].end(), v)]);
		}
		

		for (int i = m - 1; i >= 0; --i)
			lst[E[que[i]].back()] = que[i];
	}
	return 0;
}