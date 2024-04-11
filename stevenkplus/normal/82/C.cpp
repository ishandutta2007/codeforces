#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

#define time nottime
#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii> > PQ;

const int MAXN = 5010;

int A[MAXN];
PQ pqs[MAXN];

vector<pii> conn[MAXN];
int par[MAXN];
int cap[MAXN];
int ans[MAXN];

void dfs(int cur, int prv, int c) {
	par[cur] = prv;
	cap[cur] = c;
	repi(i, conn[cur]) {
		if (i->first != prv) {
			dfs(i->first, cur, i->second);
		}
	}
}

int cnt = 1;
int time = 0;
void go(int n) {
	PQ &pq = pqs[n];
	int up = par[n];
	for(int i = 0; !pq.empty() && i < cap[n]; ++i) {
		int nxt = pq.top().second; pq.pop();
		if (up == 1) {
			ans[nxt] = time;
			++cnt;
		} else {
			pqs[up].push(pii(A[nxt], nxt));
		}
	}
	repi(i, conn[n]) {
		if (i->first != up) {
			go(i->first);
		}
	}
}

int N;
int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		scanf("%d", A + i);
	}

	for(int i = 1; i < N; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		conn[a].push_back(pii(b, c));
		conn[b].push_back(pii(a, c));
	}

	dfs(1, 0, 0);

	for(int i = 2; i <= N; ++i) {
		pqs[i].push(pii(A[i], i));
	}

	while (cnt < N) {
		++time;
		go(1);
	}

	for(int i = 1; i <= N; ++i) {
		if (i != 1) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}