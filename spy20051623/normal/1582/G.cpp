#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
int a[N];
char s[N];
unordered_map<int, int> d[N];
stack<unordered_map<int, int> *> q;
vector<int> prime;
int vis[1005];

void euler() {
	for (int i = 2; i <= 1000; ++i) {
		if (!vis[i]) prime.push_back(i);
		for (int j = 0; j < prime.size() && i * prime[j] < 1000; ++j) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

void init() {
	for (int i = 1; i <= 1000000; ++i) {
		int x = i;
		for (int j: prime) {
			if (j * j > x) break;
			while (x % j == 0) {
				++d[i][j];
				x /= j;
			}
		}
		if (x > 1) ++d[i][x];
	}
}

bool check(unordered_map<int, int> &x, unordered_map<int, int> &y) {
	for (auto &i: y) {
		if (x.find(i.first) == x.end() || x[i.first] < i.second) return false;
	}
	return true;
}

void merge(unordered_map<int, int> &x, unordered_map<int, int> &y) {
	for (auto &i: y) {
		x[i.first] += i.second;
	}
}

void sub(unordered_map<int, int> &x, unordered_map<int, int> &y) {
	for (auto &i: y) {
		x[i.first] -= i.second;
		if (!x[i.first]) x.erase(i.first);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	euler();
	init();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	scanf("%s", s);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '*') {
			auto *mp = new unordered_map<int, int>;
			merge(*mp, d[a[i]]);
			q.push(mp);
		} else {
			auto *mp = new unordered_map<int, int>;
			merge(*mp, d[1]);
			q.push(mp);
			unordered_map<int, int> &cur = d[a[i]];
			while (!q.empty() && !check(*q.top(), cur)) {
				unordered_map<int, int> *p = q.top();
				q.pop();
				if (!q.empty()) {
					merge(*p, *q.top());
					delete q.top();
					q.pop();
					q.push(p);
				}
			}
			if (!q.empty()) sub(*q.top(), cur);
		}
		ans += q.size();
	}
	printf("%lld\n", ans);
	return 0;
}