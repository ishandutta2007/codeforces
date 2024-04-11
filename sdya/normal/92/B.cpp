#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxN = 1100000;
char s[maxN];

int main() {
	scanf("%s", &s);
	int n = strlen(s);
	int res = 0;
	while (n > 1) {
		if (s[n - 1] == '0') {
			++res;
			--n;
		} else {
			int j = n - 1;
			++s[j];
			while (j > 0 && s[j] == '2') {
				s[j] = '0';
				++s[j - 1];
				--j;
			}
			if (s[j] != '2') {
				++res;
			} else {
				for (int i = 1; i <= n; ++i) {
					s[i] = '0';
				}
				s[0] = '1';
				++n;
				++res;
			}
		}
	}
	cout << res << endl;
	return 0;
}