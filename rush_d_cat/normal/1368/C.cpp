#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n;
int main() {
	scanf("%d", &n);
	printf("%d\n", 3 * n + 4);
	for (int i = 0; i <= n; i ++) printf("%d %d\n", i, i);
	for (int i = 0; i <= n; i ++) printf("%d %d\n", i-1, i);
	for (int i = 0; i <= n; i ++) printf("%d %d\n", i, i-1);
	printf("%d %d\n", -1, -1);
}