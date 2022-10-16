#include <cstdio>
#include <algorithm>
const int Maxn=200000;
int sum[20][Maxn+5];
void init(){
	for(int i=0;i<20;i++){
		for(int j=1;j<=Maxn;j++){
			sum[i][j]=sum[i][j-1]+((j>>i)&1);
		}
	}
}
void solve(){
	int l,r;
	scanf("%d%d",&l,&r);
	int ans=0;
	for(int i=0;i<20;i++){
		ans=std::max(ans,sum[i][r]-sum[i][l-1]);
	}
	printf("%d\n",r-l+1-ans);
}
int main(){
	init();;
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}