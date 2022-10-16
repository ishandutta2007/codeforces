#include <cstdio>
#define Maxn 1000000
char s[Maxn+5];
bool in[Maxn+5];
int n;
int main(){
	scanf("%s",s+1);
	while(s[++n]!='\0');
	n--;
	int i=1,j=n;
	while(i<=j){
		if(i==j){
			in[i]=1;
			break;
		}
		if(s[i]==s[j]){
			in[i]=in[j]=1;
			i++,j--;
			continue;
		}
		if(s[i+1]==s[j]){
			i++;
			continue;
		}
		if(s[i]==s[j-1]){
			j--;
			continue;
		}
		i++,j--;
	}
	for(int i=1;i<=n;i++){
		if(in[i]){
			putchar(s[i]);
		}
	}
	puts("");
	return 0;
}