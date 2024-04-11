#include <stdio.h>
const int maxn = 1000100;
char s[maxn], t[maxn];
int main(){
	int n; scanf("%d", &n);
	scanf("%s%s", s + 1, t + 1);
	int cost = 0;
	for(int i = 1; i <= n; i++){
		if(i < n && s[i] != t[i] && s[i+1] != t[i+1] && s[i] != s[i+1]){
			cost++;
			s[i] = t[i];
			s[i+1] = t[i+1];
		}
		else if(s[i] != t[i]){
			cost++;
			s[i] = t[i];
		}
	}
	printf("%d\n", cost);
	return 0;
}