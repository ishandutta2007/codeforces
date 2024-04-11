#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
const int LOG = 60;

map<long long, int> cnt;
vector<long long> a;
int n;
int f[LOG];
multiset<long long> succ[LOG];

bool solve(long long v) {
	for (int i = 0; i < LOG; i++) {
		if (succ[i].size() < f[i] && (1LL << i + 1) > v) {
			succ[i].insert(v);
			return true;
		}
	}
	return false;
}

vector<int> ans;
int cur = 0;

void fuck() {
	for (int i = 0; i < LOG; i++) {
		while (f[i]) {
			long long v = -1;
			if (succ[i].size() == f[i]) {
				v = *(succ[i].begin());
				succ[i].erase(succ[i].begin());
			}
			f[i]--;
			for (int k = 0; k <= i; k++) {
				if (!solve(1LL << k)) return ;
			}
			if (v != -1 && !solve(v)) return ;
			ans.push_back(--cur);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		long long x;
		scanf("%I64d", &x);
		a.push_back(x);
		cnt[x]++;
	}
	while (cnt[1]) {
		int i = 0;
		while (cnt[1LL << i]) {
			--cnt[1LL << i];
			i++;
		}
		f[i - 1]++;
		++cur;
	}
	ans.push_back(cur);
	for (auto it : cnt) {
		long long v = it.first, num = it.second;
		while (num--) {
			// cout << "insert " << v << endl;
			bool found = false;
			for (int i = 0; i < LOG; i++) {
				if ((1LL << i + 1) > v && succ[i].size() < f[i]) {
					succ[i].insert(v);
					found = true;
					break;
				}
			}
			if (!found) {
				puts("-1");
				return 0;
			}
		}
	}
	fuck();
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
	}
	return 0;
}