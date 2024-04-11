#include <cstdio>
const int Maxn=1000000;
int n;
char l_s[Maxn+5],r_s[Maxn+5];
int main(){
	scanf("%d",&n);
	scanf("%s",l_s+1);
	scanf("%s",r_s+1);
	if(l_s[1]!=r_s[1]){
		for(int i=1;i<=n;i++){
			putchar('1');
		}
		puts("");
		return 0;
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		flag&=(l_s[i]==r_s[i]);
	}
	if(flag){
		puts(r_s+1);
		return 0;
	}
	l_s[n]++;
	for(int i=n;i>0;i--){
		if(l_s[i]>'1'){
			l_s[i]='0';
			l_s[i-1]++;
		}
	}
	flag=1;
	for(int i=1;i<=n;i++){
		flag&=(l_s[i]==r_s[i]);
	}
	if(flag){
		puts(r_s+1);
		return 0;
	}
	if(r_s[n]=='1'){
		puts(r_s+1);
		return 0;
	}
	r_s[n]++;
	puts(r_s+1);
	return 0;
}
//The crawl must have something wrong...