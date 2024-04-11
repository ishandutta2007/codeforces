#include <cstdio>
const int Maxn=50;
int n,m;
char s[Maxn+5][Maxn+5];
char t[Maxn+5][Maxn+5];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			t[i][j]=((i+j)&1)?'R':'W';
		}
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.'){
				continue;
			}
			if(s[i][j]!=t[i][j]){
				flag=0;
				break;
			}
		}
		if(!flag){
			break;
		}
	}
	if(flag){
		puts("YES");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				putchar(t[i][j]);
			}
			putchar('\n');
		}
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			t[i][j]=((i+j)&1)?'W':'R';
		}
	}
	flag=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='.'){
				continue;
			}
			if(s[i][j]!=t[i][j]){
				flag=0;
				break;
			}
		}
		if(!flag){
			break;
		}
	}
	if(flag){
		puts("YES");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				putchar(t[i][j]);
			}
			putchar('\n');
		}
		return;
	}
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}