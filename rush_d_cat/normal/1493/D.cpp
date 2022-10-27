#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL MOD = 1e9 + 7;
LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}
int n, q, a[N], pos[N], x[N];
int mn[N], vis[N];
void init() {
	for (int i = 0; i < N; i ++) mn[i] = i;
	for (int i = 2; i < N; i ++) {
		if (vis[i]) continue;
		for (int j = i + i; j < N; j += i) {
			vis[j] = 1; mn[j] = min(mn[j], i);
		}
	}
}
LL ans = 1;

multiset<int> st[N];
unordered_map<int,int> mp[N];

void add(int pos, int p, int c) {
	//printf("add %d %d %d\n", pos,p,c);
	if (mp[p].size() == n) {
		int mn = (*st[p].begin());
		ans = ans * mpow(mpow(p,mn), MOD-2) % MOD;
	}
	if (mp[p].find(pos) != mp[p].end()) 
		st[p].erase(st[p].find(mp[p][pos]));

	mp[p][pos] += c;
	st[p].insert(mp[p][pos]);
	if (mp[p].size() == n) {
		int mn = (*st[p].begin());
		ans = ans * mpow(p,mn) % MOD;
	}
}

void add(int pos, int x) {
	while (x > 1) {
		int cur = mn[x], c = 0;
		while (x % cur == 0) {
			x /= cur; c ++;
		}
		add(pos, cur, c);
	}
}

int main() {
	init();
	//printf("ok\n");
	scanf("%d%d",&n,&q);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]); add(i, a[i]);
	}
	for (int i = 1; i <= q; i ++) {
		scanf("%d%d",&pos[i],&x[i]);
		add(pos[i], x[i]);
		printf("%lld\n", ans);
	}
}