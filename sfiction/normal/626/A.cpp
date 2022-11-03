#include <cstdio>

int main(){
	int n, ans = 0;
	char s[1000];
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; ++i){
		int x = 0, y = 0;
		for (int j = i; j < n; ++j){
			if (s[j] == 'R')
				++x;
			else if (s[j] == 'L')
				--x;
			if (s[j] == 'U')
				++y;
			else if (s[j] == 'D')
				--y;
			ans += !x && !y;
		}
	}
	printf("%d\n", ans);
	return 0;
}