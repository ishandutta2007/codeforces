#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 107;
struct Tseg {
	int l, r, ID;
} seg[N];

struct cmpL {
	bool operator()(const Tseg &a, const Tseg &b)
	{return a.r < b.r || a.r == b.r && a.l < b.l;}
};

bool vis[10000007];
int ans[N];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &seg[i].l, &seg[i].r);
	for (int i = 1; i <= n; ++i) seg[i].ID = i;
	sort(seg + 1, seg + n + 1, cmpL());
	for (int i = 1; i <= n; ++i) {
		int t = seg[i].l;
		while (vis[t]) ++t;
		vis[t] = true;
		ans[seg[i].ID] = t;
	}
	for (int i = 1; i <= n; ++i) printf("%d%c", ans[i], i == n ? '\n' : ' ');
}