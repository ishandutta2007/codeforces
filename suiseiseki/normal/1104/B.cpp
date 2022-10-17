#include <cstdio>
#define Maxn 100000
char s[Maxn+5];
bool use[Maxn+5];
int main(){
	int len=0;
	scanf("%s",s+1);
	while(s[++len]!='\0');
	len--;
	int num=0;
	int last=0;
	for(int i=1;i<=len;i++){
		if(s[i]==s[last]){
			use[i]=use[last]=1;
			num++;
			last--;
			while(use[last]){
				last--;
			}
		}
		else{
			last=i;
		}
	}
	if(num&1){
		puts("Yes");
	}
	else{
		puts("No");
	}
	return 0;
}