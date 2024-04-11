#include <cstdio>
#include <algorithm>
const int Maxn=1000;
int n,m;
char s[Maxn+5];
void move_one_turn(){
	static char t[Maxn+5];
	for(int i=1;i<=n;i++){
		t[i]='0';
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			t[i]='1';
		}
		else if((s[i-1]=='1'&&s[i+1]!='1')||(s[i+1]=='1'&&s[i-1]!='1')){
			t[i]='1';
		}
	}
	for(int i=1;i<=n;i++){
		s[i]=t[i];
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	m=std::min(m,Maxn);
	while(m--){
		move_one_turn();
	}
	for(int i=1;i<=n;i++){
		putchar(s[i]);
	}
	putchar('\n');
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}