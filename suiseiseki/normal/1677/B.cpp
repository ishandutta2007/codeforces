#include <cstdio>
const int Maxn=1000000;
int n,m;
char s[Maxn+5];
bool vis[Maxn+5];
int sum[Maxn+5];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		vis[i]=0;
		sum[i]=0;
	}
	scanf("%s",s+1);
	int num=0;
	int ans_c=0;
	for(int i=1;i<=n*m;i++){
		num+=s[i]-'0';
		if(i>m){
			num-=s[i-m]-'0';
		}
		if(s[i]=='1'&&!vis[i%m]){
			vis[i%m]=1,ans_c++;
		}
		if(num==0){
			sum[i%m]++;
		}
		int ans=ans_c+(i-1)/m+1-sum[i%m];
		printf("%d ",ans);
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