#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 8E2 + 10;

struct Pair{
	int w, u, v;

	bool operator<(const Pair r)const{
		return w < r.w;
	}
};

int n;
bool vis[MAXN];
int ans[MAXN];
Pair a[MAXN * MAXN];

int main(){
	scanf("%d", &n);
	n <<= 1;
	int m = 0;
	for (int i = 2; i <= n; ++i)
		for (int j = 1; j < i; ++j){
			a[m].u = j;
			a[m].v = i;
			scanf("%d", &a[m++].w);
		}
	sort(a, a + m);
	for (int i = m - 1; i >= 0; --i)
		if (!vis[a[i].u] && !vis[a[i].v]){
			vis[a[i].u] = vis[a[i].v] = true;
			ans[a[i].u] = a[i].v;
			ans[a[i].v] = a[i].u;
		}
	for (int i = 1; i <= n; ++i)
		printf("%d%c", ans[i], "\n "[i < n]);
	return 0;
}