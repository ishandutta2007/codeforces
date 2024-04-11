#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
#define pb push_back
#define sz(x) int((x).size())
const int maxn = 100100;
const int start = 3;
vi conn[maxn];
int pos[maxn];
int tmp[maxn];
int ans[maxn];
int N;

bool con(int a, int b) {
	repi(i, conn[a])
		if (*i == b)
			return true;
	return false;
}

int beg(int cur) {
	repi(i, conn[cur])
		repi(j, conn[*i])
			++tmp[*j];
	repi(i, conn[cur])
		if (tmp[*i] >= 2)
			return *i;
	return -1;
}

bool vis(int cur, int prv, int p = start) {
	if (pos[cur]) {
		for (int i = 1; i <= N; ++i) {
			if (!pos[i]) return false;
			repi(j, conn[i]) {
				int dist = pos[i] - pos[*j];
				dist = min(dist, N - dist);
				if (dist > 2) return false;
			}
		}
		return true;
	}
	pos[cur] = p;
	repi(i, conn[cur]) {
		int nxt = *i;
		if (p - pos[nxt] > 2) {
		       if (con(nxt, prv)) {
			       if (vis (nxt, cur, p + 1)) {
				       return true;
			       }
		       }
		}
	}
	pos[cur] = 0;
	return false;
}

bool solve() {
	for (int i = 1; i <= N; ++i)
		if (sz(conn[i]) != 4) return false;
	int a = 1;
	int b = beg(a);
//	printf("beg = %d\n", b);
	if (b == -1) return false;
	if(!vis (b, a)) return false;
//	printf("Checking pos.\n");
	for (int i = 1; i <= N; ++i) {
		int ind = pos[i] - start;
		ans[ind] = i;
	}
	return true;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < 2 * N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		conn[a].pb(b);
		conn[b].pb(a);
	}
	if (solve()) {
		for (int i = 0; i < N; ++i) {
			if (i) printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	} else printf("-1\n");
	return 0;
}