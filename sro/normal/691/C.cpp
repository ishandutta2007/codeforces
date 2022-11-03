#include <bits/stdc++.h>
using namespace std;

char s[1000005];
int n;

int main(){
	scanf("%s",s);
	n=strlen(s);
	int bg=0;
	for(;s[bg]=='0'||s[bg]=='.';bg++){
	}
	int en=n-1;
	for(;s[en]=='0'||s[en]=='.';en--){
	}
	int dpos=n;
	for(int i=0;i<n;i++){
		if(s[i]=='.'){
			dpos=i;
		}
	}
	putchar(s[bg]);
	if(bg!=en){
		putchar('.');
	}
	for(int i=bg+1;i<=en;i++){
		if(s[i]!='.'){
			putchar(s[i]);
		}
	}
	if(bg+1<dpos){
		putchar('E');
		printf("%d",dpos-bg-1);
	}else if(bg>dpos){
		putchar('E');
		printf("%d",dpos-bg);
	}
	return 0;
}