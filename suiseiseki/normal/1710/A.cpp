#include <cstdio>
typedef long long ll;
const int Maxn=100000;
int n,m,k;
int a[Maxn+5];
void solve(){
	scanf("%d%d%d",&n,&m,&k);
	bool flag_n=0,flag_m=0;
	ll sum_n=0,sum_m=0;
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);
		if(a[i]/n>1){
			sum_n+=a[i]/n;
			flag_n|=a[i]/n>2;
		}
		if(a[i]/m>1){
			sum_m+=a[i]/m;
			flag_m|=a[i]/m>2;
		}
	}
	if((sum_n>=m&&(m%2==0||flag_n))||(sum_m>=n&&(n%2==0||flag_m))){
		puts("Yes");
		return;
	}
	puts("No");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}