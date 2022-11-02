#include <stdio.h>
#include <cstring>
char s[300100];
int c[2];
bool is_ans(int l, int r){
	for(int i = l; i <= r; ++i)
		for(int j = 1; i + 2 * j <= r; ++j)
			if(s[i] == s[i+j] && s[i+j] == s[i+2*j])
				return true;
	return false;
}
int main(){
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	long long ans = n * (n + 1ll) / 2;
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < 8 && i + j <= n; ++j)
			if(!is_ans(i, i + j)) --ans;
	printf("%I64d\n", ans);
	return 0;
}