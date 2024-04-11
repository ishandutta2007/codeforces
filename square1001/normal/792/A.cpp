#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, a[200009], b[200009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++) b[i] = a[i + 1] - a[i];
	int p = *min_element(b, b + n - 1), c = 0;
	for (int i = 0; i < n - 1; i++) {
		if (b[i] == p) c++;
	}
	printf("%d %d\n", p, c);
	return 0;
}