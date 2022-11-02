#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100005, MaxD = 20;

int N, Q, K, p[MaxD][MaxN], idx[MaxN], size[MaxN], Idx, q[MaxN*2], depth[MaxN], orig[MaxN], origK;
std::vector<int> e[MaxN];
bool imp[MaxN];

void go(int i, int f, int d) {
	idx[i] = Idx++;
	depth[idx[i]] = d;
	if (i) {
		p[0][idx[i]] = idx[f];
		for (int d = 0; d+1 < MaxD; d++)
			p[d+1][idx[i]] = p[d][p[d][idx[i]]];
	}
	size[idx[i]] = 1;
	for (int j : e[i]) if (j != f) {
		go(j, i, d+1);
		size[idx[i]] += size[idx[j]];
	}
}
int lca(int a, int b) {
	if (depth[a] > depth[b]) std::swap(a, b);
	for (int d = MaxD; d--; ) if (depth[b] - (1<<d) >= depth[a]) b = p[d][b];
	if (a == b) return a;
	for (int d = MaxD; d--; ) if (p[d][a] != p[d][b]) { a = p[d][a]; b = p[d][b]; }
	return p[0][a];
}
int ans, foo;
bool go2() {
	int me = q[foo];
	if (imp[q[foo]]) {
		foo++;
		while (foo < K && q[foo] < me + size[me]) {
			if (go2()) {
				//printf("inc type A at %d\n", me);
				ans++;
			}
		}
		return true;
	} else {
		foo++;
		int count = 0;
		while (foo < K && q[foo] < me + size[me]) {
			if (go2()) {
				//printf("count inc at %d\n", me);
				count++;
			}
		}
		if (count == 1) return true;
		else if (count == 0) return false;
		else {
			//printf("inc type B at %d\n", me);
			ans++;
			return false;
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N-1; i++) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		e[u].pb(v);
		e[v].pb(u);
	}
	go(0, -1, 0);
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d", &K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &q[j]); q[j]--;
			q[j] = idx[q[j]];
			orig[j] = q[j];
			imp[q[j]] = true;
		}
		origK = K;
		bool done = false;
		for (int j = 0; j < K; j++) {
			if (q[j] && imp[p[0][q[j]]]) {
				printf("-1\n");
				done = true;
				break;
			}
		}
		if (!done) {
			std::sort(q, q+K);
			for (int i = 0; i+1 < origK; i++) {
				q[K] = lca(q[i], q[i+1]);
				//printf("lca %d %d = %d\n", q[i], q[i+1], q[K]);
				K++;
			}
			std::sort(q, q+K);
			int blah = std::unique(q, q+K) - q;
			K = blah;
			//for (int i = 0; i < K; i++) printf("%d%c", q[i], " \n"[i == K-1]);
			ans = 0;
			foo = 0;
			go2();
			printf("%d\n", ans);
		}
		for (int j = 0; j < origK; j++) imp[orig[j]] = false;
	}
}