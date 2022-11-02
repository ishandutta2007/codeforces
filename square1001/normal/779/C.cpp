#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, a[200009], b[200009], c[200009], ret;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]), c[i] = max(a[i] - b[i], 0), ret += min(a[i], b[i]);
	sort(c, c + n);
	for (int i = 0; i < m; i++) ret += c[i];
	printf("%d\n", ret);
	return 0;
}