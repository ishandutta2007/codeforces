#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2E5 + 10;

int n, a[MAXN];

struct SegmentTree{
	static const int MAXN = ::MAXN;

	struct node{
		ll sum, m0, m1, val;
		ll add;
		bool odd;

		void update(ll x){
			if (odd)
				sum += x;
			m0 += x;
			val += x;
			add += x;
		}

		node operator +(const node &r){
			return (node){
				r.odd ? r.sum - sum : r.sum + sum,
				min(m0, odd ? r.m1 + sum : r.m0 - sum),
				min(m1, odd ? r.m0 - sum : r.m1 + sum),
				min(val, r.val), 0, odd ^ r.odd
			};
		}
	}a[MAXN << 2];

	void pushDown(int u){
		if (a[u].add){
			a[u << 1].update(a[u].add);
			a[u << 1 | 1].update(a[u].add);
			a[u].add = 0;
		}
	}

	void pushUp(int u){
		a[u] = a[u << 1] + a[u << 1 | 1];
	}

	void build(int u, int l, int r){
		if (l + 1 == r){
			a[u] = (node){::a[l], ::a[l], 1ll << 60, ::a[l], 0, 1};
			return;
		}
		int m = l + r >> 1;
		build(u << 1, l, m);
		build(u << 1 | 1, m, r);
		pushUp(u);
	}

	void update(int u, int l, int r, int L, int R, ll C){
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

	node query(int u, int l, int r, int L, int R){
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
}SGT;

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]), --a[i];
	SGT.build(1, 0, n);

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i){
		int type, l, r, k;
		scanf("%d%d%d", &type, &l, &r);
		++r;
		if (type == 1){
			scanf("%d", &k);
			SGT.update(1, 0, n, l, r, k);
		}
		else{
			SegmentTree::node res = SGT.query(1, 0, n, l, r);
			printf("%d\n", res.sum == 0 && res.m0 >= 0 && res.m1 >= 0 && res.val >= 0);
		}
	}
	return 0;
}