#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 1E5 + 10, MAXM = 3E5 + 10, D = 17;

int a[MAXN];

struct SegmentTree{
	static const int MAXN = ::MAXN;

	struct node{
		int val, add;

		void update(int c){
			val = min(val, c);
			if (!~add || add > c)
				add = c;
		}

		node operator +(const node &r){
			return (node){min(val, r.val), -1};
		}
	}a[MAXN << 2];

	void pushDown(int u){
		if (~a[u].add){
			a[u << 1].update(a[u].add);
			a[u << 1 | 1].update(a[u].add);
			a[u].add = -1;
		}
	}

	void pushUp(int u){
		a[u] = a[u << 1] + a[u << 1 | 1];
	}

	void build(int u, int l, int r){
		if (l + 1 == r){
			a[u] = (node){1 << 30, -1};
			return;
		}
		int m = l + r >> 1;
		build(u << 1, l, m);
		build(u << 1 | 1, m, r);
		pushUp(u);
	}

	void update(int u, int l, int r, int L, int R, int C){
		if (L <= l && r <= R){
			a[u].update(C);
			return;
		}
		pushDown(u);
		int m = l + r >> 1;
		if (L < m)
			update(u << 1, l, m, L, R, C);
		if (m < R)
			update(u << 1 | 1, m, r, L, R, C);
		pushUp(u);
	}

	node query(int u, int l, int r, int L){
		if (l + 1 == r)
			return a[u];
		pushDown(u);
		int m = l + r >> 1;
		return L < m ? query(u << 1, l, m, L) : query(u << 1 | 1, m, r, L);
	}

	node query(int u, int l, int r, int L, int R){
		if (R <= l || r <= L)
			return (node){0, -1};
		if (L <= l && r <= R)
			return a[u];
		pushDown(u);
		int m = l + r >> 1;
		if (R <= m)
			return query(u << 1, l, m, L, R);
		if (m <= L)
			return query(u << 1 | 1, m, r, L, R);
		return query(u << 1, l, m, L, R) + query(u << 1 | 1, m, r, L, R);
	}	
}SGT, SGT2;

int n, m;
int rk[MAXN];

vector<PII> lst[MAXN];

int ans[MAXM];

int main(){
	scanf("%d", &n);
	vector<int> c;
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i), c.push_back(a[i]);
	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());
	for (int i = 1; i <= n; ++i)
		rk[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
	SGT.build(1, 1, n + 1);

	scanf("%d", &m);
	for (int l ,r, i = 0; i < m; ++i){
		scanf("%d%d", &l, &r);
		lst[r].emplace_back(l, i);
	}

	fill_n(ans, m, 1 << 30);
	for (int i = 1; i <= n; ++i){
//		puts("less");
		int j = -SGT2.query(1, 0, n, rk[i], n).val;
		while (j > 0){
//			printf("update %d %d %d\n", 1, j + 1, a[j] - a[i]);
			SGT.update(1, 1, n + 1, 1, j + 1, a[j] - a[i]);
			int limit = lower_bound(c.begin(), c.end(), a[j] + a[i] + 1 >> 1) - c.begin();
			j = -SGT2.query(1, 0, n, rk[i], limit).val;
		}
//		puts("greater");
		j = -SGT2.query(1, 0, n, 0, rk[i] + 1).val;
//		printf("%d %d\n", 0, rk[i] + 1);
		while (j > 0){
//			printf("udpate %d %d %d\n", 1, j + 1, a[i] - a[j]);
			SGT.update(1, 1, n + 1, 1, j + 1, a[i] - a[j]);
			int limit = upper_bound(c.begin(), c.end(), a[j] + a[i] >> 1) - c.begin();
			j = -SGT2.query(1, 0, n, limit, rk[i] + 1).val;
		}

		SGT2.update(1, 0, n, rk[i], rk[i] + 1, -i);
		for (auto &x: lst[i])
			ans[x.nd] = SGT.query(1, 1, n + 1, x.st).val;
	}

	for (int i = 0; i < m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}