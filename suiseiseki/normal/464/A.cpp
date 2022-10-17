#include <cstdio>
#define Maxn 1000
char s[Maxn+5];
int n,p;
bool check(int x){
	if(x>=2){
		if(s[x]==s[x-1]){
			return 0;
		}
	}
	if(x>=3){
		if(s[x]==s[x-2]){
			return 0;
		}
	}
	return 1;
}
bool work(int x){
	while(x<=n){
		if(x>n){
			return 1;
		}
		if(x<1){
			return 0;
		}
		if(s[x]-'a'==p-1){
			s[x]='a'-1;
			x--;
			continue;
		}
		s[x]++;
		if(check(x)){
			x++;
		}
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&p);
	scanf("%s",s+1);
	if(work(n)){
		puts(s+1);
	}
	else{
		puts("NO");
	}
	return 0;
}