#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <ctime>
#include <queue>
#include <stack>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
//const int maxN = 10;
int n, k;
vector < int > g[maxN];
int a[maxN];

//vector < int > MM[maxN], MMR[maxN];
//vector < int > SS[maxN], SSR[maxN];

vector < int > M[maxN];
vector < int > S[maxN];

vector < int > values[maxN];

//map < int, int > M[maxN];
//map < int, int > S[maxN];

void update(vector < int > &a, int u, int v, int value) {
	int index = lower_bound(values[u].begin(), values[u].end(), v) - values[u].begin();
	a[index] = value;
}

int get(vector < int > &a, int u, int v) {
	int index = lower_bound(values[u].begin(), values[u].end(), v) - values[u].begin();
	return a[index];
}

void dfsS(int v, int parent) {
	int res = 1;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != parent) {
			dfsS(g[v][i], v);
			res += get(S[g[v][i]], g[v][i], v);
		}
	}
	update(S[v], v, parent, res);
}

void dfs(int v, int parent, int bound) {
	vector < int > children;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != parent) {
			children.push_back(g[v][i]);
			dfs(g[v][i], v, bound);
		}
	}

	int total = 0;
	int best = 0;
	for (int i = 0; i < children.size(); ++i) {
		int u = children[i];
		int index = lower_bound(values[u].begin(), values[u].end(), v) - values[u].begin();
		int value = M[u][index];
		if (value == S[u][index]) {
			total += value;
		} else {
			best = max(best, value);
		}
	}
	if (a[v] >= bound) {
		update(M[v], v, parent, total + best + 1);
	}
}

void dfsA(int v, int parent, int parentScore, int parentSum, int bound) {
	int totals = 0;
	multiset < int > W;
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != parent) {
			int u = g[v][i];
			int muv = get(M[u], u, v);
			int suv = get(S[u], u, v);
			if (muv == suv) {
				totals += muv;
			} else {
				W.insert(muv);
				if (W.size() > 2) {
					W.erase(W.begin());
				}
			}
		}
	}
	for (int i = 0; i < g[v].size(); ++i) {
		if (g[v][i] != parent) {
			int u = g[v][i];
			int newTotal = totals;
			int newBest = 0;
			int index = lower_bound(values[u].begin(), values[u].end(), v) - values[u].begin();
			int muv = M[u][index];
			int suv = S[u][index];
			bool deleted = false;
			if (muv == suv) {
				newTotal -= muv;
			} else {
				auto it = W.find(muv);
				if (it != W.end()) {
					deleted = true;
					W.erase(it);
				}
			}
			if (!W.empty()) {
				newBest = max(newBest, *W.rbegin());
			}
			if (deleted) {
				W.insert(muv);
			}

			int pScore = parentScore;
			if (pScore == parentSum) {
				newTotal += pScore;
			} else {
				newBest = max(newBest, pScore);
			}
			int mV = 0;
			index = i + 1;
			if (a[v] >= bound) {
				M[v][index] = newTotal + newBest + 1;
				mV = newTotal + newBest + 1;
			}
			S[v][index] = n - suv;
			dfsA(u, v, mV, n - suv, bound);
		}
	}
}

bool check(int bound) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < M[i].size(); ++j) {
			M[i][j] = S[i][j] = 0;
		}
	}
	dfsS(0, -1);
	dfs(0, -1, bound);
	dfsA(0, -1, 0, 0, bound);

	int res = 0;
	for (int i = 0; i < n; ++i) {
		int total = 0;
		int best = 0;
		for (int j = 0; j < g[i].size(); ++j) {
			int index = lower_bound(values[g[i][j]].begin(), values[g[i][j]].end(), i) - values[g[i][j]].begin();
			int s = S[g[i][j]][index];
			int m = M[g[i][j]][index];
			if (s == m) {
				total += m;
			} else {
				best = max(best, m);
			}
		}
		if (a[i] >= bound) {
			res = max(res, 1 + total + best);
		}
	}
	return res >= k;
}

void gen() {
	int n = 200000, k = rand() + 1;
	printf("%d %d\n", n, k);
	for (int i = 0; i < n; ++i) {
		printf("%d ", rand() + 1);
	}
	printf("\n");

	for (int i = 1; i < n; ++i) {
		printf("%d %d\n", i + 1, (rand() % i) + 1);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();
	//return 0;

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 0; i < n; ++i) {
		sort(g[i].begin(), g[i].end());
		values[i].push_back(-1);
		for (int j = 0; j < g[i].size(); ++j) {
			values[i].push_back(g[i][j]);
		}
		sort(values[i].begin(), values[i].end());
		M[i].assign(values[i].size(), 0);
		S[i].assign(values[i].size(), 0);
	}

	int left_bound = 0, right_bound = 1000000;
	while (right_bound - left_bound > 1) {
		int middle = (left_bound + right_bound) / 2;
		if (check(middle)) {
			left_bound = middle;
		} else {
			right_bound = middle;
		}
		//cerr << clock() << endl;
	}

	int res = 0;
	if (check(right_bound)) {
		res = max(res, right_bound);
	} else {
		res = max(res, left_bound);
	}
	cout << res << endl;

	cerr << clock() << endl;

	return 0;
}