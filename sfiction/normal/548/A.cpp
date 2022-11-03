/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 548A
 */
#include <cstdio>
#include <cstring>

const int MAXN = 1E3 + 10;

char s[MAXN];
int n, k, len;

bool palindrome(char *a, char *b){
	--b;
	while (a < b && *a == *b){
		++a;
		--b;
	}
	return a >= b;
}

int main(){
	scanf("%s", s);
	scanf("%d", &k);
	n = strlen(s);
	if (n % k == 0){
		len = n / k;
		bool flag = true;
		for (char *t = s; *t; t += len)
			if (!palindrome(t, t + len))
				flag = false;
		puts(flag ? "YES" : "NO");
	}
	else
		puts("NO");
	return 0;
}