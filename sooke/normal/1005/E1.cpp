#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define lol long long

inline int read() {
	char c = getchar();
	int n = 0, f = 0;
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = 1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar();
	}
	return f ? -n : n;
}

#define MAXN 200005

map<int, int> A, B;
int n, m, a[MAXN], pre[MAXN];
bool flag = true;
lol ans;

int main() {
	n = read(), m = read();
	B[0]++;
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		if (a[i] < m) {
			a[i] = -1;
		} else if (a[i] == m) {
			a[i] = 0;
			flag = false;
		} else {
			a[i] = 1;
		}
		pre[i] = pre[i - 1] + a[i];
		if (i & 1) {
			if (flag || a[i] == 0) {
				A[pre[i]]++;	
			}
			if (!flag){
				ans += B[pre[i]] + A[pre[i] - 1];	
			}
		} else {
			if (flag || a[i] == 0) {
				B[pre[i]]++;	
			}
			if (!flag){
				ans += A[pre[i]] + B[pre[i] - 1];	
			}
		}
	}
	printf("%I64d\n", ans);
	return 0;
}

// By Sooke.