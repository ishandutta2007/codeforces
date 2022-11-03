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

const int MAXN = 1E5 + 10;
const ll MOD = 1E9 + 7;

struct mat{
	ll a, b, c;
};

mat operator +(const mat &l, const mat &r){
	return (mat){(l.a + r.a) % MOD, (l.b + r.b) % MOD, (l.c + r.c) % MOD};
}

mat operator *(const mat &l, const mat &r){
	return (mat){(l.a * r.a + l.b * r.b) % MOD, (l.a * r.b + l.b * r.c) % MOD, (l.b * r.b + l.c * r.c) % MOD};
}

int a[MAXN];

mat modExp(mat e, ll n){
	mat ret = (mat){1, 0, 1};
	for (; n; n >>= 1, e = e * e)
		if (n & 1)
			ret = ret * e;
	return ret;
}

struct SegmentTree{
	const int MAXNN = ::MAXN;

	struct node{
		mat val, add;
		bool flag;

		void update(mat c){
			val = val * c;
			add = add * c;
			flag = true;
		}

		node operator +(const node &r){
			return (node){val + r.val, (mat){1, 0, 1}, false};
		}
	};

	node a[MAXN << 2];

	void pushDown(int u){
		if (a[u].flag){
			a[u << 1].update(a[u].add);
			a[u << 1 | 1].update(a[u].add);
			a[u].add = (mat){1, 0, 1};
			a[u].flag = false;
		}
	}

	void build(int u, int l, int r){
		if (l + 1 == r){
			a[u].val = modExp((mat){1, 1, 0}, ::a[l]);
			return;
		}
		int m = l + r >> 1;
		build(u << 1, l, m);
		build(u << 1 | 1, m, r);
		a[u] = a[u << 1] + a[u << 1 | 1];
	}

	void update(int u, int l, int r, int L, int R, mat C){
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
		a[u] = a[u << 1] + a[u << 1 | 1];
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
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	SGT.build(1, 1, n + 1);
	for (int com, l, r, x, i = 0; i < m; ++i){
		scanf("%d%d%d", &com, &l, &r);
		if (com == 1){
			scanf("%d", &x);
			SGT.update(1, 1, n + 1, l, r + 1, modExp((mat){1, 1, 0}, x));
		}
		else
			printf("%d\n", (int)(SGT.query(1, 1, n + 1, l, r + 1).val.b));
	}
	return 0;
}