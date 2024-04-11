#include <cstdio>
const int Maxn=500000;
int n;
char s[Maxn+5];
int deg[Maxn<<1|5];
void solve(){
	scanf("%s",s+1);
	n=0;
	while(s[++n]!='\0');
	n--;
	for(int i=0;i<=(n<<1|1);i++){
		deg[i]=0;
	}
	int pos=n;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			deg[pos]++;
			pos++;
		}
		else{
			pos--;
			deg[pos]++;
		}
	}
	for(int i=n,j=n;j--;){
		if(deg[i-1]>0&&(deg[i]==0||deg[i-1]>1)){
			i--;
			deg[i]--;
			putchar('0');
		}
		else{
			deg[i]--;
			i++;
			putchar('1');
		}
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}