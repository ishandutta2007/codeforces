#include <cstdio>
#include <algorithm>

using namespace std;

const int SIGMA = 26, MAXL = 1E3 + 10;

char s[MAXL];
int cnt2[SIGMA][SIGMA];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%s", s);
		int mask = 0;
		char *p = s;
		for (; *p; ++p)
			mask |= 1 << *p - 'a';
		int t = __builtin_popcount(mask);
		if (t <= 2)
			cnt2[__builtin_ctz(mask)][31 - __builtin_clz(mask)] += p - s;
	}
	int ans = 0;
	for (int i = 0; i < SIGMA; ++i)
		for (int j = i + 1; j < SIGMA; ++j)
			ans = max(ans, cnt2[i][j] + cnt2[i][i] + cnt2[j][j]);
	printf("%d\n", ans);
	return 0;
}