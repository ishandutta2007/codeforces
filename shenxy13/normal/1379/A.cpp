#include <cstdio>
#include <algorithm>
using namespace std;
const char str[7] = {'a', 'b', 'a', 'c', 'a', 'b', 'a'};
int main() {
	int T;
	scanf("%d", &T);
	for (int h = 0; h < T; ++h) {
		int n;
		scanf("%d", &n);
		char s[n];
		for (int i = 0; i < n; ++i) scanf(" %c", &s[i]);
		for (int i = 0; i < n - 6; ++i) {
			char ans[n];
			for (int j = 0; j < n; ++j) ans[j] = s[j];
			for (int j = i; j < i + 7; ++j) {
				if (ans[j] == '?') ans[j] = str[j - i];
			}
			for (int j = 0; j < n; ++j) {
				if (ans[j] == '?') ans[j] = 'd';
			}
			int num_sstr = 0;
			for (int j = 0; j < n - 6; ++j) {
				bool isstr = true;
				for (int k = j; k < j + 7; ++k) isstr &= (ans[k] == str[k - j]);
				num_sstr += isstr;
			}
			if (num_sstr == 1) {
				printf("Yes\n");
				for (int j = 0; j < n; ++j) printf("%c", ans[j]);
				printf("\n");
				goto hell;
			}
		}
		printf("No\n");
		hell:;
	}
}