///	D : Coded by Choe Kwang

#include <bits/stdc++.h>
using namespace std;
#define N 1010

int n, a, b;
pair <int, int> p[N], q[N];
bool vis[N];
vector <int> v;

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%d %d", &a, &b);
		if (a > b) swap(a, b);
		q[i].first = a, q[i].second = b;
	}
	sort(q, q + n);
	int m = unique(q, q + n) - q;
    for (int i = 0; i < m; i ++) {
		for (int j = i + 1; j < m; j ++) {
			if (q[j].second <= q[i].second) {vis[i] = 1; break;}
		}
    }
    n = 0;
    for (int i = 0; i < m; i ++) if (!vis[i]) p[n++] = q[i];
    memset(vis, 0, sizeof vis);
	for (int i = 0; i < n; i ++) {
		if (vis[i]) continue;
		v.push_back(p[i].second);
		for (int j = i; j < n; j ++) if (p[j].first <= p[i].second && p[j].second >= p[i].second) vis[j] = 1;
	}
	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i ++) printf("%d ", v[i]); puts("");
	return 0;
}