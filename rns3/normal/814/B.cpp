#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, p[N], a[N], b[N];
int vis[N], tag[N];

bool ok() {
	int now = 0;
	for (int i = 1; i <= n; i ++) if (a[i] != p[i]) now ++;
	if (now != 1) return 0;
	now = 0;
	for (int i = 1; i <= n; i ++) if (b[i] != p[i]) now ++;
	if (now != 1) return 0;
	return 1;
}

void putans() {
	for (int i = 1; i <= n; i ++) printf("%d ", p[i]);
}

int main() {
	scanf("%d", &n);
	int flag1 = 0, flag2 = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]), vis[a[i]] ++;
		if (vis[a[i]] > 1) flag1 = a[i];
	}
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &b[i]), tag[b[i]] ++;
		if (tag[b[i]] > 1) flag2 = b[i];
	}
    if (flag1) {
    	int rmh;
    	for (int i = 1; i <= n; i ++) if (!vis[i]) rmh = i;
		for (int i = 1; i <= n; i ++) p[i] = a[i];
		for (int i = 1; i <= n; i ++) {
			if (a[i] == flag1) {
				p[i] = rmh;
				if (ok()) {
					putans();
					return 0;
				}
				p[i] = a[i];
			}
		}
    }
    else if (flag2) {
    	int rmh;
    	for (int i = 1; i <= n; i ++) if (!tag[i]) rmh = i;
		for (int i = 1; i <= n; i ++) p[i] = b[i];
		for (int i = 1; i <= n; i ++) {
			if (b[i] == flag2) {
				p[i] = rmh;
				if (ok()) {
					putans();
					return 0;
				}
				p[i] = b[i];
			}
		}
    }

	return 0;
}