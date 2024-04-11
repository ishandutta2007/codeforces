#include <cstdio>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin() , _##i = (a).end(); i != _##i; ++i)
const int MAXN = 310;

int par[MAXN];
int find(int x) {
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}
void join(int a, int b) {
	a = find(a);
	b = find(b);
	par[a] = b;
}

struct step {
	int x;
	int y;
	int d;
	step(int a, int b, int c) {
		x = a;
		y = b;
		d = c;
	}
};

vector<int> conn[MAXN];
vector<step> ans;

int ar[MAXN];
int need[MAXN];

int N, V, E;



int deg[MAXN];
bool vis[MAXN];

void steal(int amt, int to, int from) {
	if (amt == 0) return;
	if (ar[from] < amt) {
		repi(i, conn[from]) {
			if (!vis[*i] && *i != to) {
				int diff = amt - ar[from];
				steal(diff, from, *i);
			}
		}
	}

	int sum = amt;
	if (ar[from] < sum) sum = ar[from];

	ans.push_back(step(from, to, sum));
	ar[to] += sum;
	ar[from] -= sum;
}

void give(int amt, int from, int to) {
	if (amt == 0) return;
	int cap = V - ar[to];
	if (cap < amt) {
		repi(i, conn[to]) {
			if (!vis[*i] && *i != from) {
				int cap = V - ar[to];
				int diff = amt - cap;
				give(diff, to, *i);
			}
		}
	}

	cap = V - ar[to];
	int sum = amt;
	if (sum > cap) sum = cap;
	ans.push_back(step(from, to, sum));
	ar[to] += sum;
	ar[from] -= sum;
}

void solve(int x) {
	vis[x] = true;
	int diff = need[x] - ar[x];

	int par;
	repi(i, conn[x]) {
		if (!vis[*i]) {
			par = *i;
			break;
		}
	}

	if (diff > 0)
		steal(diff, x, par);
	else
		give(-diff, x, par);
	--deg[par];
	if (deg[par] == 1) solve(par);
}



int main() {
	scanf("%d %d %d", &N, &V, &E);

	for(int i = 1; i <= N; ++i) {
		scanf("%d", ar + i);
	}
	for(int i = 1; i <= N; ++i) {
		scanf("%d", need + i);
	}

	for(int i = 1; i <= N; ++i) par[i] = i;

	for(int i = 0; i < E; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (find(a) != find(b)) {
			join(a, b);
			conn[a].push_back(b);
			conn[b].push_back(a);
			++deg[a];
			++deg[b];
		}
	}

	for(int i = 1; i <= N; ++i) {
		if (!vis[i] && deg[i] == 1) {
			solve(i);
		}

		if (!vis[i] && deg[i] == 0) {
			if (ar[i] != need[i]) {
				printf("NO\n");
				return 0;
			}
		}
	}

	printf("%d\n", int(ans.size()));
	for(int i = 0; i < int(ans.size()); ++i) {
		printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].d);
	}
	return 0;
}