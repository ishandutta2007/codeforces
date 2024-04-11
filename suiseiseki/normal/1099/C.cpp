#include <cstdio>
#define Maxn 200
char s[Maxn+5];
int main(){
	int n;
	scanf("%s",s+1);
	n=0;
	while(s[++n]!='\0');
	n--;
	int k;
	scanf("%d",&k);
	int now=0;
	int del;
	for(int i=1;i<=n;i++){
		if(s[i]!='*'&&s[i]!='?'){
			now++;
		}
	}
	if(now==k){
		for(int i=1;i<=n;i++){
			if(s[i]!='*'&&s[i]!='?'){
				putchar(s[i]);
			}
		}
		puts("");
	}
	else if(now>k){
		if(now-(n-now)>k){
			puts("Impossible");
		}
		else{
			del=now-k;
			for(int i=1;i<=n;i++){
				if(s[i]!='*'&&s[i]!='?'){
					if(del==0){
						putchar(s[i]);
					}
					else{
						if(s[i+1]!='*'&&s[i+1]!='?'){
							putchar(s[i]);
						}
						else{
							del--;
						}
					}
				}
			}
			puts("");
		}
	}
	else{
		del=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='*'){
				del=1;
				break;
			}
		}
		if(del==0){
			puts("Impossible");
		}
		else{
			del=0;
			for(int i=1;i<=n;i++){
				if(s[i]!='*'&&s[i]!='?'){
					putchar(s[i]);
					if(s[i+1]=='*'&&del==0){
						del=1;
						while(now<k){
							now++;
							putchar(s[i]);
						}
					}
				}
			}
			puts("");
		}
	}
	return 0;
}