#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

struct QueueWithMax {
	static const int maxN = 200000;
	long long a[maxN];
	long long maxs[maxN];
	int ml, mr;
	int l, r;
	QueueWithMax() {
		ml = 0, mr = -1;
		l = 0, r = -1;
	}
	void clear() {
		ml = 0, mr = -1;
		l = 0, r = -1;
	}
	void push(long long value) {
		a[++r] = value;
		while (mr >= ml && value > maxs[mr]) {
			--mr;
		}
		maxs[++mr] = value;
	}
	void pop() {
		long long value = a[l++];
		if (value == maxs[ml]) {
			++ml;
		}
	}
	long long get() {
		return maxs[ml];
	}
};

const int maxN = 160000;
const long long inf = 1000000000000000000LL;
int n, m, d;
long long dp[2][maxN];
int u, v;

QueueWithMax q;

void update(long long d, int a, int b) {
	for (int i = 1; i <= n; ++i) {
		dp[v][i] = -inf;
	}

	if (d >= n - 1) {
		d = n - 1;
	}

	q.clear();
	long long added = b;
	for (int i = 1; i <= 1 + d; ++i) {
		q.push(dp[u][i]);
	}
	for (int i = 1; i <= n; ++i) {
		dp[v][i] = max(dp[v][i], q.get() + added - (long long)(abs(a - i)));
		q.pop();
		if (i + d + 1 <= n) {
			q.push(dp[u][i + d + 1]);
		}
	}

	q.clear();
	added = b;
	for (int i = n; i >= n - d; --i) {
		q.push(dp[u][i]);
	}
	for (int i = n; i >= 1; --i) {
		dp[v][i] = max(dp[v][i], q.get() + added - (long long)(abs(a - i)));
		q.pop();
		if (i - d - 1 >= 1) {
			q.push(dp[u][i - d - 1]);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &d);
	u = 0, v = 1;
	for (int i = 1; i <= n; ++i) {
		dp[u][i] = 0;
	}

	int t = 1;
	for (int i = 0; i < m; ++i, swap(u, v)) {
		int a, b, ct;
		scanf("%d%d%d", &a, &b, &ct);
		long long dist = (long long)(d) * (long long)(ct - t);
		t = ct;

		update(dist, a, b);
	}
	long long res = -inf;
	for (int i = 1; i <= n; ++i) {
		res = max(res, dp[u][i]);
	}
	cout << res << endl;

	return 0;
}