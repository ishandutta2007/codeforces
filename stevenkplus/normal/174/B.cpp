#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 400100;

char str[MAXN];
bool sep[MAXN];

int N;

bool solve() {
	int prv = -1;
	for(int i = 0; i < N; ++i) {
		if (str[i] == '.') {
			if (prv == -1) {
				if (i == 0) return false;
				if (i > 8) return false;
			} else {
				int len = i - prv - 1;
				if (len <= 1) return false;
				if (len > 11) return false;
				if (len >= 4) {
					sep[prv + 4] = true;
				} else {
					sep[prv + 2] = true;
				}
			}
			prv = i;
		}
	}
	if (prv == -1) return false;
	int len = N - prv - 1;
	return len >= 1 && len <= 3;
}

int main() {
	scanf("%s", str);
	N = strlen(str);
	if (solve()) {
		printf("YES\n");
		for(int i = 0; i < N; ++i) {
			if (sep[i]) {
				printf("\n");
			}
			printf("%c", str[i]);
		}
		printf("\n");
	} else {
		printf("NO\n");
	}
	return 0;
}