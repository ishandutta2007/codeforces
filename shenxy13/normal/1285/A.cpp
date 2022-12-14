#include <cstdio>
#include <algorithm>
using namespace std;
const long long mod = 1000000007;
int main() {
	int n, a = 0, b = 0;
	scanf("%d", &n);
	char c;
	for (int i = 0; i < n; ++i) {
		scanf(" %c", &c);
		if (c == 'L') ++a;
		else ++b;
	}
	printf("%d", a + b + 1);
	return 0;
}