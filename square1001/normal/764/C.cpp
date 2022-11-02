#include <vector>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;
int n, a[100009], b[100009], c[100009], e[100009];
int main() {
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) scanf("%d%d", &a[i], &b[i]), a[i]--, b[i]--;
	for (int i = 0; i < n; i++) scanf("%d", &c[i]);
	for (int i = 0; i < n - 1; i++) {
		if (c[a[i]] != c[b[i]]) cnt++, e[a[i]]++, e[b[i]]++;
	}
	int ptr = -1;
	for (int i = 0; i < n; i++) {
		if (e[i] == cnt) ptr = i;
	}
	if (ptr == -1) puts("NO");
	else {
		puts("YES");
		printf("%d\n", ptr + 1);
	}
	return 0;
}