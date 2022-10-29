#include <cctype>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <algorithm>

using namespace std;

char s[100500];
bool used[256];

int main() {
	scanf(" %s", s);
	int n = strlen(s);
	int numsign = 0;
	int ftype = 0;
	int ans = 1;
	int numal = 0;
	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			if (isdigit(s[i])) 
				ftype = 0;
			else if (isalpha(s[i]))
				ftype = 1;
			else
				ftype = 2;// s[i] == '?'
		}
		if (isalpha(s[i])) {
			if (!used[s[i] - 'A'])
				used[s[i] - 'A'] = true, ++numal;
		}
		if (s[i] == '?' && i) ++numsign;
	}
	for (int cur = 10, i = 0; i < numal; ++i, --cur)
		ans *= cur;
	if (ftype == 1)
		ans = ans / 10 * 9;
	if (ftype == 2)
		ans = ans * 9;
	printf("%d", ans);
	for (int i = 0; i < numsign && ans; ++i)
		printf("0");
	printf("\n");
	return 0;
}