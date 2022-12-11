#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

char str[200];
int val[200];

int main() {
	scanf("%s", str);
	int n = strlen(str);
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'A') val[i] = 1;
		if (str[i] == 'B') val[i] = 2;
		if (str[i] == 'C') val[i] = 4;
	}
	for (int i = 1; i < n - 1; ++i) {
		if (val[i-1] + val[i] + val[i+1] == 7) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}