#include <cstdio>

using namespace std;

const int MAXN = 110;

int par[MAXN];

int find(int n) {
	if (par[n] == n) return n;
	return par[n] = find(par[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	par[a] = b;
}

int N;
int ar[MAXN];

bool go() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		scanf("%d", ar + i);
	}

	for(int i = 1; i <= N; ++i) {
		par[i] = i;
	}

	for(int i = 1; i <= N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		if (i - tmp >= 1) {
			merge(i, i - tmp);
		}
		if (i + tmp <= N) {
			merge(i, i + tmp);
		}
	}

	for(int i = 1; i <= N; ++i) {
		if (find(i) != find(ar[i])) {
			return false;
		}
	}
	return true;
}

int main() {
	if (go()) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}