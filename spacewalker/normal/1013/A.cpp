#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	int aSum = 0, bSum = 0, temp = 0;
	for (int i = 0; i < n; ++i) scanf("%d", &temp), aSum += temp;
	for (int i = 0; i < n; ++i) scanf("%d", &temp), bSum += temp;
	if (aSum >= bSum) printf("Yes\n");
	else printf("No\n");
	return 0;
}