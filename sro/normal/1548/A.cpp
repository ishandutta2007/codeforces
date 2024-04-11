#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;

int N, M;
set<int> si[200005];
int pro[200005], prs;

void inline add(int a, int b) {
	si[a].insert(b);
	prs -= pro[a];
	pro[a] = !SZ(si[a]) || *--si[a].end() < a;
	prs += pro[a];
}

void inline rem(int a, int b) {
	si[a].erase(b);
	prs -= pro[a];
	pro[a] = !SZ(si[a]) || *--si[a].end() < a;
	prs += pro[a];
}

int main() {
	scanf("%d%d", &N, &M);
	repi(i, N) pro[i] = 1, ++prs;
	repi(i, M) {
		int u, v; scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	int Q; scanf("%d", &Q);
	while (Q--) {
		int op; scanf("%d", &op);
		int u, v;
		switch (op) {
		case 1:
			scanf("%d%d", &u, &v);
			add(u, v); add(v, u);
			break;
		case 2:
			scanf("%d%d", &u, &v);
			rem(u, v); rem(v, u);
			break;
		case 3:
			printf("%d\n", prs);
		}
	}
	return 0;
}