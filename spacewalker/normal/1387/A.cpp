#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int INF = 1000000000;

struct LinearExp { // represents ax + b
	ll a, b;
	LinearExp() : a(0), b(0) {}
	LinearExp(ll k) : a(0), b(k) {}
	LinearExp(ll a, ll b) : a(a), b(b) {}
	LinearExp operator+ (LinearExp other) {
		return LinearExp(a + other.a, b + other.b);
	}
	LinearExp operator- (LinearExp other) {
		return LinearExp(a - other.a, b - other.b);
	}
	// 1 = always solvable
	// 0 = not solvable for val
	// -1 = solvable only for val
	int isSolvable(ll val) {
		if (a != 0) return 1;
		else if (b == val) return -1;
		else return 0;
	}
	// is garbage if isSolvable is 0
	float getSolution(ll val) {
		if (a == 0) return 1;
		else return (val - b) / (float)a;
	}
	float substitute(float x) {
		return a * x + b;
	}
	LinearExp operator* (ll x) {
		return LinearExp(a * x, b * x);
	}
};

float absMinimizer(vector<LinearExp> values) {
	for (LinearExp &l : values) if (l.a == -1) l = l * -1;
	vector<float> constants;
	for (LinearExp l : values) constants.push_back(-l.b);
	sort(begin(constants), end(constants));
	int n = constants.size();
	return constants[n/2];
}

// returns True iff the answer found was valid
bool clearComponent(vector<vector<pair<int, int>>> &graph, vector<bool> &isVisited, vector<float> &ans, vector<LinearExp> &intermediates, int st) {
	int n = graph.size();
	vector<int> que;
	isVisited[st] = true;
	que.push_back(st);
	intermediates[st] = LinearExp(1, 0);
	for (int elem = 0; elem < que.size(); ++elem) {
		int cur = que[elem];
		for (auto [nxt, esum] : graph[cur]) {
			if (!isVisited[nxt]) {
				isVisited[nxt] = true;
				intermediates[nxt] = LinearExp(esum) - intermediates[cur];
				que.push_back(nxt);
			}
		}
	}
	for (int v : que) assert(intermediates[v].a == 1 || intermediates[v].a == -1);
	// check if this arrangement is valid
	float fixedX = INF; // always stays within half-ints... i hope?
	for (int v : que) {
		for (auto [nxt, esum] : graph[v]) {
			LinearExp combSum = intermediates[v] + intermediates[nxt];
			if (combSum.isSolvable(esum) == 0) return false;
			else if (combSum.isSolvable(esum) == 1) {
				float xForced = combSum.getSolution(esum);
				if (fixedX < INF && xForced != fixedX) return false;
				fixedX = xForced;
			}
		}
	}
	if (fixedX == INF) {
		vector<LinearExp> exprs;
		for (int v : que) exprs.push_back(intermediates[v]);
		fixedX = absMinimizer(exprs);
	}
	for (int v : que) ans[v] = intermediates[v].substitute(fixedX);
	return true;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<vector<pair<int, int>>> graph(n);
	for (int i = 0; i < m; ++i) {
		int x, y, v; scanf("%d %d %d", &x, &y, &v);
		--x; --y;
		graph[x].emplace_back(y, v);
		graph[y].emplace_back(x, v);
	}
	vector<bool> isVisited(n);
	vector<float> ans(n);
	vector<LinearExp> intermediates(n);
	for (int i = 0; i < n; ++i) {
		if (!isVisited[i] && !clearComponent(graph, isVisited, ans, intermediates, i)) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (float v : ans) printf("%.3f ", v);
	printf("\n");
	return 0;
}