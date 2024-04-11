#include <bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define db double
#define mod 998244353
#define maxn 10005
using namespace std;
ll ksm(ll a, ll b) {
	if (!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if (b & 1) ns = ns * a % mod;
	return ns;
}
int col[maxn];
int fl[maxn];
void work(vi x, int tm) {
	if (x.empty()) return ;
	for (int i = 0; i < x.size(); i++)
		fl[x[i]] = 0;
	vector<vi> s(x.size());
	set<int> qq;
	for (int i = 0; i < x.size(); i++) {
		set<int>::iterator it = qq.lower_bound(x[i]);
		if (it != qq.end()) s[i].pb(*it);
		if (it != qq.begin()) s[i].pb(*(--it));
		qq.insert(x[i]);
	}
	for (int i = x.size() - 1; i >= 0; i--) {
		if (!fl[x[i]]) {
			fl[x[i]] = 1;
			for (int j = 0; j < s[i].size(); j++)
				fl[s[i][j]] = -1;
			col[x[i]] = tm;
		}
	}
	vi y;
	for (int i = 0; i < x.size(); i++)
		if (fl[x[i]] != 1) y.pb(x[i]);
	work(y, tm + 1);
	
}
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		vi r(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &r[i]);
		work(r, 1);
		for (int i = 1; i <= n; i++)
			printf("%d ", col[i]);
		printf("\n");
	}
	return 0;
}
/*
4 5 4 2
1 3 3 4
7 8

4 3 3 1
3 2 2
6

*/