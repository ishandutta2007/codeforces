#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
vector<vector<int>> bef;
int calls[maxn];
bool co[maxn];
bool dn[maxn];

void proc(int u) {
	calls[u] = 0;
	if (co[u]) {
		calls[u] = 1;
	}
	dn[u] = true;
	bool ot = false;
	for (int i = 0; i < bef[u].size(); i++) {
		int v = bef[u][i];
		if (!dn[v]) {
			proc(v);
		}
		if (co[v]) ot = true;
		if (co[u] && co[v]) {
			calls[u] = max(calls[u], calls[v]);
		}
		if (!co[u]) {
			calls[u] = max(calls[u], calls[v]);
		}
		if (co[u] && !co[v]) {
			calls[u] = max(calls[u], calls[v]+1);
		}
	}
	
	// cout << "u  " << u << "  " << calls[u] << endl;
}	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	bool islast[N+1];
	for (int i = 0; i <= N; i++) {
		vector<int> bl;
		bef.push_back(bl);
		islast[i] = true;
		dn[i] = false;
	}
	int cur;
	for (int i = 1; i <= N; i++) {
		cin >> cur;
		if (cur == 1) {
			co[i] = true;
		}
		else co[i] = false;
	}
	int t1, t2;
	for (int i = 0; i < M; i++) {

		cin >> t1 >> t2;
		t1++;
		t2++;
		bef[t1].push_back(t2);
		islast[t2] = false;
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (islast[i]) {
			proc(i);
			ans = max(ans, calls[i]);
		}
	}
	cout << ans << endl;
	cin >> ans;
}