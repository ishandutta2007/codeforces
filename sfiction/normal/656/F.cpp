#include <cstdio>

int main(){
	char s[10];
	scanf("%s", s);
	int ans = 1;
	for (int i = 1; i < 7;){
		int t = s[i] - '0';
		for (++i; i < 7 && s[i] == '0'; ++i)
			t *= 10;
		ans += t;
	}
	printf("%d\n", ans);
	return 0;
}