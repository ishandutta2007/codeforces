#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 300100;

int N, Q;
int ar[MAXN];
int pos[MAXN];
int val[MAXN];
int BIT[MAXN];

void add(int x, int v) {
	while (x < MAXN) {
		BIT[x] += v;
		x += x & -x;
	}
}

int query(int x) {
	int ret = 0;
	while (x) {
		ret += BIT[x];
		x -= x & -x;
	}
	return ret;
}

void set(int x, int v) {
	int diff = v - val[x];
	val[x] = v;
	add(x, diff);
}

void refresh(int x) {
	if (x < N && x > 0) {
		if (pos[x + 1] < pos[x]) {
			set(x, 1);
		} else {
			set(x, 0);
		}
	}
}

int qquery(int x) {
	int ret = 0;
	for(int i = 1; i <= x; ++i) {
		ret += val[i];
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		scanf("%d", ar + i);
		pos[ar[i]] = i;
	}

	for(int i = 1; i < N; ++i) {
		if (pos[i + 1] < pos[i]) {
			set(i, 1);
		}
	}

	scanf("%d", &Q);
	for(int q = 0; q < Q; ++q) {
		int qtype, x, y;
		scanf("%d %d %d", &qtype, &x, &y);

		if (qtype == 1) {
			int ans = query(y - 1) - query(x - 1) + 1;
			printf("%d\n", ans);
		} else {
			swap(ar[x], ar[y]);
			swap(pos[ar[x]], pos[ar[y]]);

			refresh(ar[x]);
			refresh(ar[x] - 1);
			refresh(ar[y]);
			refresh(ar[y] - 1);
		}


		/*printf("val:");
		for(int i = 1; i <= N; ++i) {
			printf("%d ", val[i]);
		}
		printf("\n");*/
	}

	return 0;
}