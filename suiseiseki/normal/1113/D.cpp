#include <cstdio>
#define Maxn 5000
char s[Maxn<<1|5];
int n;
bool check(int x){
	for(int i=x,j=x+n-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			return 0;
		}
	}
	for(int i=x;i<=x+n-1;i++){
		if(s[i]!=s[i-x+1]){
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	char c=s[1];
	for(int i=2;i<=n;i++){
		if((n&1)&&(i==((n+1)>>1))){
			continue;
		}
		if(c!=s[i]){
			c='\0';
			break;
		}
	}
	if(c!='\0'){
		puts("Impossible");
		return 0;
	}
	s[n+1]=s[1];
	for(int i=2;i<=n;i++){
		s[i+n]=s[i];
		if(check(i)){
			puts("1");
			return 0;
		}
	}
	puts("2");
	return 0;
}