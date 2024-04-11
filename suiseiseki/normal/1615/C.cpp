#include <cstdio>
#include <algorithm>
const int Maxn=100000;
int n;
char a[Maxn+5],b[Maxn+5];
void solve(){
	scanf("%d",&n);
	scanf("%s",a+1);
	scanf("%s",b+1);
	int ans_0=0,ans_1=0;
	int num_0=0,num_1=0;
	for(int i=1;i<=n;i++){
		ans_0+=(a[i]!=b[i]);
		num_0+=(a[i]!=b[i]&&a[i]=='1');
		ans_1+=(a[i]==b[i]);
		num_1+=(a[i]==b[i]&&a[i]=='1');
	}
	int ans=n+1;
	if(~ans_0&1){
		if(num_0*2==ans_0){
			ans=std::min(ans,ans_0);
		}
	}
	if(ans_1&1){
		if(num_1*2-1==ans_1){
			ans=std::min(ans,ans_1);
		}
	}
	if(ans>n){
		ans=-1;
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