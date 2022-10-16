#include <cstdio>
const int Maxn=1000000;
const int Mod=1000000007;
int n,m;
char s[Maxn+5];
void solve(){
	scanf("%d",&n);
	scanf("%s",s+1);
	m=0;
	while(s[++m]!='\0');
	m--;
	int ans=m;
	for(int i=1;i<=n;i++){
		int cur_m=m;
		for(int j=1;j<s[i]-'0'&&m<n;j++){
			for(int k=i+1;k<=cur_m&&m<n;k++){
				s[++m]=s[k];
			}
		}
		ans=(i+1ll*(ans-i+Mod)*(s[i]-'0'))%Mod;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}