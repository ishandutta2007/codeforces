#include<bits/stdc++.h>

using namespace std;
using INT = long long;

const int NN = 100011;
int n;
int a[NN], c[NN];
INT ans;
int id[NN];

bool cmp(int u, int v) {
	return a[u]+c[u] < a[v]+c[v];
}

int solve() {
	for(int i=1; i<=n; i++) ans += c[i], id[i] = i;
	sort(id+1, id+n+1, cmp);
	int pre=n;
	INT x=0;
	INT now;
	for(int i=n-1, j; i>=1; i--) {
		j = id[i];
		now = x;
		int tmp = a[id[pre]]-c[j]-a[j];
		if(tmp>0) now += tmp;
		if(a[id[pre]] > a[id[i]]) {
			pre=i;
			x = now;
		}
	}
	ans += now;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		scanf("%d %d", a + i, c + i);
	}
	solve();
	cout << ans << endl;

}