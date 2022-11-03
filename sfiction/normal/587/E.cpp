/*
 * 
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2E5 + 10, MAXK = 31, MAXK2 = MAXK << 1;

int n;
int a[MAXN];

int num[MAXN << 2];
int b[MAXN << 2][MAXK];
int L, R, C;
int A[MAXK];

void merge(int c[], int a[], int b[]){
	static int d[MAXK2];
	for (int i = 0; i < MAXK; ++i){
		d[i] = a[i];
		d[MAXK + i] = b[i];
	}

	for (int e = 1, j, k = 0, i = 0; i < MAXK; ++i, e <<= 1){
		for (j = k; j < MAXK2 && !(d[j] & e); ++j);
		if (j == MAXK2)
			continue;
		swap(d[k], d[j]);
		for (++j; j < MAXK2; ++j)
			if (d[j] & e)
				d[j] ^= d[k];
		++k;
	}

	for (int i = 0; i < MAXK; ++i)
		c[i] = d[i];
}

void build(int u, int l, int r){
	if (l + 1 == r){
		num[u] = a[l];
		b[u][0] = num[u];
		return;
	}
	int m = l + r >> 1;
	build(u << 1, l, m);
	build(u << 1 | 1, m, r);
	num[u] = num[u << 1] ^ num[u << 1 | 1];
	merge(b[u], b[u << 1], b[u << 1 | 1]);
}

void update(int u, int l, int r){
	if (l + 1 == r){
		num[u] ^= C;
		b[u][0] = num[u];
		return;
	}
	int m = l + r >> 1;
	if (L < m)
		update(u << 1, l, m);
	else
		update(u << 1 | 1, m, r);
	num[u] = num[u << 1] ^ num[u << 1 | 1];
	merge(b[u], b[u << 1], b[u << 1 | 1]);
}

void queryNum(int u, int l, int r){
	if (L <= l && r <= R){
		C ^= num[u];
		return;
	}
	int m = l + r >> 1;
	if (L < m)
		queryNum(u << 1, l, m);
	if (m < R)
		queryNum(u << 1 | 1, m, r);
}

void queryXor(int u, int l, int r){
	if (L <= l && r <= R){
		merge(A, A, b[u]);
		return;
	}
	int m = l + r >> 1;
	if (L < m)
		queryXor(u << 1, l, m);
	if (m < R)
		queryXor(u << 1 | 1, m, r);
}

int main(){
	int q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = n; i > 1; --i)
		a[i] ^= a[i - 1];
	build(1, 1, n + 1);

	int com, l, r;
	for (int i = 0; i < q; ++i){
		scanf("%d%d%d", &com, &l, &r);
		if (com == 1){
			scanf("%d", &C);
			L = l;
			update(1, 1, n + 1);
			if (r < n){
				L = r + 1;
				update(1, 1, n + 1);
			}
		}
		else{
			L = 1, R = l + 1, C = 0;
			queryNum(1, 1, n + 1);

			memset(A, 0, sizeof(A));
			A[0] = C;
			if (l < r){
				L = l + 1, R = r + 1;
				queryXor(1, 1, n + 1);
			}

			int cnt = 0;
			for (int j = 0; j < MAXK; ++j)
				cnt += !!A[j];
			printf("%d\n", 1 << cnt);
		}
	}
	return 0;
}