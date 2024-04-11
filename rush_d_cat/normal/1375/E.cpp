#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1002;
int t, n;
int a[N], nex[N];
vector<int> g[N];
void solve(int u) {
	vector< pair<int,int> > vec;
	for (auto v: g[u]) {
		vec.push_back(make_pair(a[v], v));
	}
	sort(vec.begin(), vec.end());
	memset(nex, 0, sizeof(nex));
	if (vec.size() == 0) return;
	for (int i = 1; i < vec.size(); i ++) {
		nex[vec[i].second] = vec[i-1].second;
	}
	int mxpos = vec.back().second;
	int now = mxpos;
	while (1) {
		printf("%d %d\n", u, now);
		now = nex[now];
		if (now == 0) break;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			if (a[i] > a[j]) {cnt ++; g[i].push_back(j);}
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i ++) solve(i);
}