#include <cstdio>

char s[200];
int n, k;

bool check(int x){
	for(int i=1; i<=x; i++)
		if(s[i] != s[n - x + i]) return false; 
	return true;
}

int main(){
	scanf("%d%d", &n, &k);
	scanf("%s", s+1);
	int same = 0;
	for(int i=1; i<n; i++)
		if(check(i)) same = i;
	if(same == n) same = n-1;
	printf("%s", s+1);
	for(int i=1; i<k; i++)
		for(int i=same+1; i<=n; i++) putchar(s[i]);
	puts("");
	return 0;
}