#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
typedef long long ll;
int n, m, x; ll a[200009];
int main() {
	scanf("%d%d%d", &n, &m, &x);
	int fxor = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		if (a[i] < 0) fxor ^= 1;
	}
	for (int i = 0; i < n && m > 0; i++) {
		if (a[i] != 0) continue;
		if (fxor == 0) a[i] -= x, fxor ^= 1, m--;
		else a[i] += x, m--;
	}
	if (fxor == 0) {
		int ptr = 0;
		for (int i = 1; i < n; i++) {
			if (abs(a[ptr]) > abs(a[i])) ptr = i;
		}
		bool revflag = false;
		if (a[ptr] > 0) a[ptr] = -a[ptr], revflag = true;
		while (a[ptr] <= 0 && m > 0) a[ptr] += x, m--;
		if (a[ptr] > 0) fxor ^= 1;
		if (revflag) a[ptr] = -a[ptr];
	}
	priority_queue<pair<ll, int> > que;
	for (int i = 0; i < n; i++) que.push(make_pair(-abs(a[i]), i));
	while (m > 0) {
		int u = que.top().second; que.pop();
		if (a[u] < 0) a[u] -= x;
		else a[u] += x;
		que.push(make_pair(-abs(a[u]), u)); m--;
	}
	for (int i = 0; i < n; i++) printf(i ? " %lld" : "%lld", a[i]);
	printf("\n");
	return 0;
}