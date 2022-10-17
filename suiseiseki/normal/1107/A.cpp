#include <cstdio>
#define Maxn 300
char s[Maxn+5];
int main(){
	int t;
	int n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",s+1);
		if(n==2&&s[1]>=s[2]){
			puts("NO");
			continue;
		}
		puts("YES");
		puts("2");
		printf("%c ",s[1]);
		for(int i=2;i<=n;i++){
			putchar(s[i]);
		}
		puts("");
	}
	return 0;
}