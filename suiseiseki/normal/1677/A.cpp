#include <cstdio>
typedef long long ll;
const int Maxn=5000;
int n;
int p[Maxn+5];
int sum_l[Maxn+5][Maxn+5],sum_r[Maxn+5][Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		sum_l[i][p[i]]++;
		sum_r[i][p[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum_l[i][j]+=sum_l[i-1][j];
		}
	}
	for(int i=n;i>0;i--){
		for(int j=1;j<=n;j++){
			sum_r[i][j]+=sum_r[i+1][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum_l[i][j]+=sum_l[i][j-1];
			sum_r[i][j]+=sum_r[i][j-1];
		}
	}
	ll ans=0;
	for(int i=2;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans+=1ll*sum_l[i-1][p[j]-1]*sum_r[j+1][p[i]-1];
		}
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum_l[i][j]=sum_r[i][j]=0;
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}