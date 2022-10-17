#include <cstdio>
#define Maxn 100
char s[Maxn+5];
int main(){
	int t;
	int n,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++){
			s[i]=(i%k)+'a';
		}
		s[n]='\0';
		puts(s);
	}
	return 0;
}