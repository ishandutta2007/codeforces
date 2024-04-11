/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 550A
 */
#include <cstdio>
#include <cstring>

const int MAXN = 1E5 + 100;

char s[MAXN];

bool check(char *s, const char *a, const char *b){
	char *p = strstr(s, a);
	return p != NULL && strstr(p + strlen(a), b) != NULL;
}

int main(){
	scanf("%s", &s);
	puts(check(s, "AB", "BA") || check(s, "BA", "AB") ? "YES" : "NO");
	return 0;
}