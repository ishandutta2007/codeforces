#include <cstdio>
#define Maxn 1000
#define ll long long
char s[Maxn+5];
bool f[Maxn+5];
int main(){
	scanf("%s",s+1);
	int len=0;
	while(s[++len]!='\0');
	len--;
	for(int i=1;i<len;i++){
		if(s[i]!=s[i+1]){
			f[i]=1;
		}
	}
	if(s[len]=='a'){
		f[len]=1;
	}
	for(int i=1;i<=len;i++){
		printf("%d ",f[i]);
	}
	puts("");
	return 0;
}