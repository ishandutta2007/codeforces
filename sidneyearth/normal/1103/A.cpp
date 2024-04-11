#include <stdio.h>
char s[1010];
int main(){
	scanf("%s", s);
	for(int i = 0, a = 1, b = 1; s[i]; i++){
		if(s[i] == '0'){
			printf("%d %d\n", a, 1);
			a = 4 - a;
		}
		else{
			printf("%d %d\n", b, 2);
			b = b % 4 + 1;
		}
	}
	return 0;
}