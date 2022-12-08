#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define pii pair<int, int>

const int maxn = 200010;

ll a[maxn];
int b[maxn];
int inp[maxn];
vector<int> aft[maxn];
int deg[maxn];

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (b[i] != -1) {
			inp[b[i]]++;
		}
	}
	ll res = 0LL;
	vector<int> q;
	for (int i = 1; i <= n; i++) {
		if (inp[i] == 0) q.push_back(i);
	}
	while (q.size()) {
		int cur = q.back();
		q.pop_back();
		res += a[cur];
		if (b[cur] == -1) continue;
		if (a[cur] > 0) {
			a[b[cur]]+= a[cur];
			aft[cur].push_back(b[cur]);
			deg[b[cur]]++;
		}
		else {
			aft[b[cur]].push_back(cur);
			deg[cur]++;
		}
		inp[b[cur]]--;
		if (inp[b[cur]] == 0) {
			q.push_back(b[cur]);
		}
	}
	cout << res << endl;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) {
			q.push_back(i);
		}
	}
	while (q.size()) {
		int cur = q.back();
		q.pop_back();
		cout << cur << " ";
		for (int v : aft[cur]) {
			deg[v]--;
			if (deg[v] == 0) q.push_back(v);
		}
	}
	cout << endl;
}