#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
typedef vector<int>::iterator it;

const int MAXN = 100100;

vector<int> rows[MAXN];

int anc[MAXN];
int k[MAXN];

vector<int> queries[MAXN];
vector<int> child[MAXN];
int level[MAXN];
int first[MAXN];
int last[MAXN];

int N, Q;

int stk[MAXN];
void dfs(int cur, int &cnt, int depth = 0) {
	level[cur] = depth;
	first[cur] = cnt;
	rows[depth].push_back(cnt);
	++cnt;
	stk[depth] = cur;

	repi(i, queries[cur]) {
		int up = k[*i];
		if (depth >= up) {
			anc[*i] = stk[depth - up];
		} else {
		}
	}

	repi(i, child[cur]) {
		dfs(*i, cnt, depth + 1);
	}
	last[cur] = cnt;
}

int ask(int n, int k) {
	if (n == 0) return 0;
	int row = level[n] + k;
	int a = first[n];
	int b = last[n];
	vector<int> &v = rows[row];
	it lft = lower_bound(v.begin(), v.end(), a);
	it rgt = upper_bound(v.begin(), v.end(), b);
	return int(rgt - lft);
}

vector<int> roots;
int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		int par;
		scanf("%d", &par);
		if (par) {
			child[par].push_back(i);
		} else {
			roots.push_back(i);
		}
	}

	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		queries[a].push_back(i);
		k[i] = b;
	}

	int tmp = 0;
	repi(i, roots) {
		dfs(*i, tmp);
	}

	for(int i = 0; i < Q; ++i) {
		int ans = ask(anc[i], k[i]);
		if (ans) --ans;
		if (i) printf(" ");
		printf("%d", ans);
	}
	printf("\n");

	return 0;
}