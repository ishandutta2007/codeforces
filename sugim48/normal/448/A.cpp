#include <cstdio>
using namespace std;

int main() {
	int a1, a2, a3;
	scanf("%d%d%d", &a1, &a2, &a3);
	int b1, b2, b3;
	scanf("%d%d%d", &b1, &b2, &b3);
	int n;
	scanf("%d", &n);
	n -= (a1 + a2 + a3 + 4) / 5;
	n -= (b1 + b2 + b3 + 9) / 10;
	printf(n >= 0 ? "YES\n" : "NO\n");
}