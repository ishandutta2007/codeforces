#include <cstdio>

const int MAXN = 510;
const int MAXM = 10100;

int N, M;
int Q;
int par[MAXN];

void init() {
	for(int i = 1; i <= N; ++i) {
		par[i] = i;
	}
}

int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}

bool join(int a, int b) {
	a = find(a);
	b = find(b);
	par[a] = b;
	return a != b;
}


int A[MAXM];
int B[MAXM];

int prefs[MAXN];
int suffs[MAXN];
int cnt1, cnt2;

int main() {
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= M; ++i) {
		scanf("%d %d", A + i, B + i);
	}

	init();
	cnt1 = 0;
	for(int i = 1; i <= M; ++i) {
		if (join(A[i], B[i])) {
			prefs[cnt1] = i;
			++cnt1;
		}
	}

	init();
	cnt2 = 0;
	for(int i = M; i >= 1; --i) {
		if (join(A[i], B[i])) {
			suffs[cnt2] = i;
			++cnt2;
		}
	}

	scanf("%d", &Q);
	for(int q = 0; q < Q; ++q) {
		int l, r;
		scanf("%d %d", &l, &r);
		init();
		int num = N;
		for(int i = 0; i < cnt1; ++i) {
			int ed = prefs[i];
			if (ed < l) {
				if (join(A[ed], B[ed])) --num;
			} else break;
		}
		for(int i = 0; i < cnt2; ++i) {
			int ed = suffs[i];
			if (ed > r) {
				if(join(A[ed], B[ed])) --num;
			} else break;
		}

		printf("%d\n", num);
	}

	return 0;
}