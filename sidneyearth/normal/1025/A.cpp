#include <stdio.h>
char s[100100];
int f[30];
int main(){
	int n; scanf("%d", &n);
	scanf("%s", s);
	bool ans = n == 1;
	for(int i = 0; i < n; i++){
		if(f[s[i] - 'a']) ans = true;
		f[s[i] - 'a'] = true;
	}
	printf("%s\n", ans ? "YES" : "NO");
	return 0;
}