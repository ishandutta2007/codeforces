#include <cctype>
#include <cstdio>

int cnt[26];

int main(){
	int n, ans = 0;
	bool flag = true;
	scanf("%d\n", &n);
	for (char c; islower(c = getchar()); )
		ans += !!cnt[c - 'a']++;
	printf("%d\n", 26 < n ? -1 : ans);
	return 0;
}