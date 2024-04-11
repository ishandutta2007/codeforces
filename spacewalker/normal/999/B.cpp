#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char str[200];

int main() {
	int n; scanf("%d", &n);
	scanf("%s", str);
	for (int sLen = 1; sLen <= n; ++sLen) {
		if (n % sLen == 0) {
			reverse(str, str + sLen);
		}
	}
	printf("%s\n", str);
	return 0;
}