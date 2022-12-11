#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;
typedef long long ll;

bool areChangeable(char a, char b) {
	return (a == b) or (abs(a - b) == 2);
}

char str[10000];

int main() {
	// printf("here\n");
	int t; scanf("%d", &t);
	// printf("here")
	while (t--) {
		int n; scanf("%d", &n);
		scanf("%s", str);
		bool possible = true;
		for (int i = 0; i < n; ++i) {
			if (!areChangeable(str[i], str[n-1-i])) {
				possible = false;
			}
		}
		printf("%s\n", (possible ? "YES" : "NO"));
	}
	return 0;
}