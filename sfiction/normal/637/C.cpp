#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E3 + 10, LEN = 6;

char s[MAXN][LEN + 1];

int diff(char a[], char b[]){
	int ret = 0;
	for (int i = 0; i < LEN; ++i)
		ret += a[i] != b[i];
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	int ans = 13;
	for (int i = 0; i < n; ++i){
		scanf("%s", s[i]);
		for (int j = 0; j < i; ++j)
			ans = min(ans, diff(s[i], s[j]));
	}
	printf("%d\n", ans - 1 >> 1);
	return 0;
}