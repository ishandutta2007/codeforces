#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E5 + 10;

int n, K;
char s[MAXN];

int solve(char chr){
	int ret = s[0] == chr;
	for (int t = 1 - ret, l = 0, r = 1; r < n; ++r){
		t += s[r] != chr;
		for (; K < t; t -= s[l++] != chr);
		ret = max(ret, r - l + 1);
	}
	return ret;
}

int main(){
	scanf("%d%d", &n, &K);
	scanf("%s", s);
	printf("%d\n", max(solve('a'), solve('b')));
	return 0;
}