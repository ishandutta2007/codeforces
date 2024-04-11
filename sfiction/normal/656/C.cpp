#include <cctype>
#include <cstdio>

int main(){
	char s[100];
	scanf("%s", s);
	int ans = 0;
	for (int i = 0; s[i]; ++i){
		if (isalpha(s[i])){
			if (s[i] <= 'Z')
				ans += s[i] - 'A' + 1;
			else
				ans -= s[i] - 'a' + 1;
		}
		/*
		int a = '@' < s[i] & '[' > s[i];
		int b = '`' < s[i] & '{' > s[i];
		int c = tolower(s[i]) - 'a';
		ans += a * b - c * b;*/
	}
	printf("%d\n", ans);
	return 0;
}