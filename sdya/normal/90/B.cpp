#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxN = 110;
char s[maxN][maxN];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			bool isOk = true;
			for (int k = 0; k < max(n, m); ++k) {
				if (k != j && s[i][k] == s[i][j]) {
					isOk = false;
				}
				if (k != i && s[k][j] == s[i][j]) {
					isOk = false;
				}
			}
			if (isOk) {
				printf("%c", s[i][j]);
			}
		}
	}
	printf("\n");
	return 0;
}