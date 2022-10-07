#include <cstdio>

typedef long long ll;
const int MAXN = 1 << 17;
const int SIZE = MAXN << 1;
const int ROWS = 48;
const int MOD = 95542721;

int seg[SIZE][ROWS];
int rowl[SIZE];
int rowr[SIZE];

int N, Q;
int ar[MAXN];

void init(int cur = 1, int l = 0, int r = MAXN) {
	if (l + 1 == r) {
		ll prod = ar[l] % MOD;
		for(int i = 0; i < ROWS; ++i) {
			seg[cur][i] = prod;
			prod = ((prod * prod) % MOD * prod) % MOD;
		}
	} else {
		int childl = cur * 2, childr = childl + 1;
		int mid = (l + r) / 2;
		init(childl, l, mid);
		init(childr, mid, r);

		for(int i = 0; i < ROWS; ++i) {
			seg[cur][i] = (seg[childl][i] + seg[childr][i]) % MOD;
		}
	}
}

void slide(int left, int right, int cur = 1, int l = 0, int r = MAXN) {
	if (right <= l || r <= left) {
		return;
	}

	int childl = cur * 2, childr = childl + 1;
	int mid = (l + r) / 2;
	if (left <= l && mid <= right) {
		++rowl[cur];
	} else {
		slide(left, right, childl, l, mid);
	}

	if (left <= mid && r <= right) {
		++rowr[cur];
	} else {
		slide(left, right, childr, mid, r);
	}

	for(int i = 0; i < ROWS; ++i) {
		int rl = (rowl[cur] + i) % ROWS;
		int rr = (rowr[cur] + i) % ROWS;
		seg[cur][i] = (seg[childl][rl] + seg[childr][rr]) % MOD;
	}
}

int query(int left, int right, int cur = 1, int row = 0, int l = 0, int r = MAXN) {
	if (right <= l || r <= left) {
		return 0;
	}

	if (left <= l && r <= right) {
		return seg[cur][row];
	}

	int childl = cur * 2, childr = childl + 1;
	int mid = (l + r) / 2;
	int rl = (row + rowl[cur]) % ROWS;
	int rr = (row + rowr[cur]) % ROWS;
	return (query(left, right, childl, rl, l, mid) + query(left, right, childr, rr, mid, r)) % MOD;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		scanf("%d", ar + i);
	}
	//printf("Initializing.\n");
	init();

	//printf("Processing queries.\n");
	scanf("%d", &Q);
	for(int q = 0; q < Q; ++q) {
		int qtype, left, right;
		scanf("%d %d %d", &qtype, &left, &right);
		++right;
		if (qtype == 1) {
			//printf("Querying %d %d\n", left, right);
			int ans = query(left, right);
			printf("%d\n", ans);
		} else if (qtype == 2) {
			//printf("Sliding %d %d\n", left, right);
			slide(left, right);
		}
	}

	return 0;
}