#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n, b[N], c, d, m[N];
char t[N];
int e, f;
pair <int, int> u[N], v[N];

int main() {
	scanf("%d %d %d", &n, &c, &d);
	for (int i = 1; i <= n; i ++) {
		scanf("%d %d %c", &b[i], &m[i], &t[i]);
		if (t[i] == 'C') u[++e] = make_pair(m[i], b[i]);
		else v[++f] = make_pair(m[i], b[i]);
	}
	int x = 0, y = 0, z = 0;
	sort (u + 1, u + e + 1);
	sort (v + 1, v + f + 1);
    int k = 0, h = 0;
    for (int i = 1; i <= e; i ++) {
		if (u[i].first > c) {
			e = i - 1;
			break;
		}
		else k = max(k, u[i].second);
    }
    for (int i = 1; i <= f; i ++) {
		if (v[i].first > d) {
			f = i - 1;
			break;
		}
		else h = max(h, v[i].second);
    }
    if (k && h) x = h + k;
    int i = 0, now[N] = {0}, j;
    for (j = e; j > i; j --) {
		while (i < j - 1 && u[i+1].first <= c - u[j].first) {
			i ++;
			now[i] = max(now[i-1], u[i].second);
		}
		if (i) y = max(y, now[i] + u[j].second);
    }
    for (; j > 1; j --) {
		y = max(y, now[j-1] + u[j].second);
    }
    memset(now, 0, sizeof now);
    i = 0;
    for (j = f; j > i; j --) {
		while (i < j - 1 && v[i+1].first <= d - v[j].first) {
			i ++;
			now[i] = max(now[i-1], v[i].second);
		}
		if (i) z = max(z, now[i] + v[j].second);
    }
    for (; j > 1; j --) {
		z = max(z, now[j-1] + v[j].second);
    }
    printf("%d\n", max(x, max(y, z)));
	return 0;
}