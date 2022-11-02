#include <bits/stdc++.h>
using namespace std;

#define N 202020

int a[N], n;


int e;
int tic[N], tac[N];
bool vis[N];

void put_ans() {
	if (!e) {
		for (int i = 1; i < n; i ++) printf("1 %d %d\n", i, i + 1);
	}
	else {
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= e; i ++) vis[tic[i]] = 1;
		int f = 0;
		for (int i = 1; i <= n; i ++) if (!vis[i]) tac[++f] = i;
		for (int i = 1; i < e; i ++) printf("1 %d %d\n", tic[i], tic[i+1]);
		printf("2 %d\n", tic[e]);
		for (int i = 1; i < f; i ++) {
			printf("1 %d %d\n", tac[i], tac[i+1]);
		}
	}
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	int zero = 0;
	for (int i = 1; i <= n; i ++) if (!a[i]) zero ++;
	int neg = 0;
	for (int i = 1; i <= n; i ++) if (a[i] < 0) neg ++;
	int mxid;
	if (neg) {
		mxid = -1;
		for (int i = 1; i <= n; i ++) if (a[i] < 0) {
			if (mxid == -1 || a[i] > a[mxid]) mxid = i;
		}
	}
	if (zero) {
		for (int i = 1; i <= n; i ++) if (!a[i]) tic[++e] = i;
		if (neg & 1) {
			tic[++e] = mxid;
			if (e == n) {
				swap(tic[e], tic[1]);
				e --;
			}
		}
		else {
			if (e == n) e --;
		}
	}
	else {
		if (neg & 1) tic[++e] = mxid;
	}
	put_ans();

	return 0;
}