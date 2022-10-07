#include <cstdio>

using namespace std;

struct node {
	int x, y;
	node() {x = 0; y = 0;}
};

const int MAXN = 1 << 17;
const int SIZE = MAXN << 1;

node seg[SIZE];

void down(int cur) {
	int childl = cur * 2;
	int childr = childl + 1;
	if (childr >= SIZE) return;
	if (seg[cur].x) {
		seg[childl] = seg[cur];
		seg[childr] = seg[cur];
		seg[cur].x = 0;
	        seg[cur].y = 0;
	}
}

node query(int idx, int cur = 1, int l = 0, int r = MAXN) {
//	printf("querying at %d\n", cur);
	if (idx == l && idx + 1 == r) {
		return seg[cur];
	} else {
		down(cur);
		int childl = cur * 2;
		int childr = childl + 1;
		int mid = (l + r) / 2;
		if (mid > idx) return query(idx, childl, l, mid);
		else return query(idx, childr, mid, r);
	}
}

void upd(int left, int right, node &val, int cur = 1, int l = 0, int r = MAXN) {
//	printf("updating at %d\n", cur);
	down(cur);
	if (left >= r || right <= l) return;
	if (left <= l && r <= right) {
//		printf("Setting %d\n", cur);
		seg[cur] = val;
	} else {
		int childl = cur * 2;
		int childr = childl + 1;
		int mid = (l + r) / 2;
		upd(left, right, val, childl, l, mid);
		upd(left, right, val, childr, mid, r);
	}
}

int A[MAXN];
int B[MAXN];

int N, M;

int q(int x) {
//	printf("Querying %d:", x);
	node n = query(x);
//	printf("got %d %d\n", n.x, n.y);
	if (n.x == 0) {
		return B[x];
	} else {
		return A[n.x + x - n.y];
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; ++i) {
		scanf("%d", A + i);
	}
	for(int i = 1; i <= N; ++i) {
		scanf("%d", B + i);
	}

	for(int i = 0; i < M; ++i) {
		int qtype;
		scanf("%d", &qtype);
		if (qtype == 1) {
			int x, y, k;
			scanf("%d %d %d", &x, &y, &k);
			node n;
			n.x = x;
			n.y = y;
			upd(y, y + k, n);
		} else {
			int x;
			scanf("%d", &x);
			int ans = q(x);
			printf("%d\n", ans);
		}
	}
	return 0;
}