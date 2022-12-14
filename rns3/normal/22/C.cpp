#include <stdio.h>
#include <algorithm>
#include<iostream>
using namespace std;

#define N 100010

int n, m, v, a[N];

int main() {
	scanf("%d %d %d", &n, &m, &v);
	if (m < n - 1 || (n - 1) * (n - 2) / 2 < m - 1) puts("-1");
	else {
		for (int i = 1; i <= n; i ++) a[i] = i;
		swap(a[v], a[n-1]);
		for (int i = 1; i < n; i ++) printf("%d %d\n", a[i], a[i+1]);
		m -= (n - 1);
		for (int i = 1; i < n - 2; i ++) for (int j = i + 2; j < n; j ++) {
			if (!m) return 0;
			printf("%d %d\n", a[i], a[j]);
			m --;
		}
	}
	return 0;
}