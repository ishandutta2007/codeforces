#include <bits/stdc++.h>
using namespace std;
#define N 1010000
int a[N];
typedef long long ll;

int son[N * 30][2];
int num[N * 30];

int tot;

int new_node() {
	++tot;
	son[tot][0] = son[tot][1] = 0;
	num[tot] = 0;
	return tot;
}

int root;

int mx = 0;

void add(int x) {
	int c = root;
	for(int i = 30; i >=0; i --) {
		int id = (x >> i) & 1;
		if(!son[c][id]) {
			son[c][id] = new_node();
		}
		int y = son[c][id];
		num[y] ++;
		mx = max(mx, num[y]);
		c = y;
	}
	return ;
}

int K;

int calc(int x) {
	int c = root;
	int ans = 0;
	for(int i = 30; i >= 0; i --) {
		int aa = (x >> i) & 1;
		int bb = (K >> i) & 1;
		aa = aa ^ bb;
		if(!bb) {
			ans += num[son[c][1 - aa]] ;
		}
		int y = son[c][aa];
		c = y;
		if(!y) return ans;
	}
	return ans;
}

int main() {
	//freopen("1.in", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	scanf("%d%d", &n, &K);
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	a[0] = 0;
	for(int i = 1; i <= n; i ++) a[i] = a[i - 1] ^ a[i];
	K --;
	tot = 0;
	root = new_node();
	int xx = root;
	add(0);
	ll ans = 0;
	for(int i = 1; i <= n; i ++) {
		ans += calc(a[i]);
		add(a[i]);
	}
	printf("%I64d\n", ans);
	return 0;
}