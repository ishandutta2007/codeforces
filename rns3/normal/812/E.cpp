#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, p[N], a[N], dist[N], q[N];
bool vis[N];

vector <int> v[N];

map<int, int> mp, mp1;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 2; i <= n; i ++) {
		scanf("%d", &p[i]);
		v[p[i]].push_back(i);
	}
    int e = 0;
    q[++e] = 1;
    dist[1] = 0;
    for (int f = 1, now; f <= e; f ++) {
		now = q[f];
		for (int i = 0, sz = v[now].size(); i < sz; i ++) {
			q[++e] = v[now][i];
            dist[q[e]] = dist[now] + 1;
		}
    }
    int tag = dist[q[e]] % 2, rmh = 0;
    for (int i = 1; i <= n; i ++) {
		if (dist[i] % 2 == tag) {
			vis[i] = 1;
			rmh ^= a[i];
		}
		else mp[a[i]] ++;
    }
	long long ans = 0;
    if (rmh) {
		for (int i = 1; i <= n; i ++) if (vis[i]) {
			if (mp.count(rmh ^ a[i])) ans += mp[rmh^a[i]];
		}
    }
    else {
        int kk = 0;
        for (int i = 1; i <= n; i ++) if (vis[i]) {
			kk ++;
			mp1[a[i]] ++;
		}
		ans += 1ll * kk * (kk - 1) + 1ll * (n - kk) * (n - kk - 1);
        for (int i = 1; i <= n; i ++) {
            if (vis[i]) ans += mp[a[i]];
			else ans += mp1[a[i]];
        }
		ans /= 2;
    }
	printf("%I64d\n", ans);
	return 0;
}