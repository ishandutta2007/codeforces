#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E5 + 10;

struct SegmentTree{
	static const int MAXN = ::MAXN;

	struct node{
		int val, add;

		void update(int c){
			val += c;
			add += c;
		}

		node operator +(const node &r){
			return (node){max(val, r.val), 0};
		}
	}a[MAXN << 2];

	void pushDown(int u){
		if (a[u].add){
			a[u << 1].update(a[u].add);
			a[u << 1 | 1].update(a[u].add);
			a[u].add = 0;
		}
	}

	void update(int u, int l, int r, int R, int c){
		if (r <= R){
			a[u].update(c);
			return;
		}
		pushDown(u);
		int m = l + r >> 1;
		update(u << 1, l, m, R, c);
		if (m < R)
			update(u << 1 | 1, m, r, R, c);
		a[u] = a[u << 1] + a[u << 1 | 1];
	}

	int query(int u, int l, int r){
		if (l + 1 == r)
			return a[u].val > 0 ? l : 0;
		pushDown(u);
		int m = l + r >> 1;
		return a[u << 1 | 1].val <= 0 ? query(u << 1, l, m)
					: query(u << 1 | 1, m, r);
	}
}SGT;

int n;
int a[MAXN];

int main(){
	scanf("%d", &n);
	a[0] = -1;
	for (int l, com, i = 0; i < n; ++i){
		scanf("%d%d", &l, &com);
		if (com)
			scanf("%d", a + l);
		SGT.update(1, 1, n + 1, l + 1, com * 2 - 1);
		printf("%d\n", a[SGT.query(1, 1, n + 1)]);
	}
	return 0;
}