#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, s, a[200009], c[200009];
int main() {
	scanf("%d %d", &n, &s); s--;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (i != s) c[a[i]]++;
	}
	int ret = n - 1, sc = 0, sb = 0;
	for (int i = 1; i < n; i++) {
		sc += c[i]; sb += c[i] == 0;
		ret = min(ret, max(n - sc - 1, sb));
	}
	if (a[s] != 0) ret++;
	printf("%d\n", ret);
	return 0;
}