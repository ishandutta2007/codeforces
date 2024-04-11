#include <cstdio>
const int Maxn=200000;
char s[Maxn+5];
void solve(){
	scanf("%s",s+1);
	int n=0;
	while(s[++n]!='\0');
	n--;
	if(s[n]!='B'){
		puts("NO");
		return;
	}
	int num=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='B'){
			num--;
			if(num<0){
				puts("NO");
				return;
			}
		}
		else{
			num++;
		}
	}
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}