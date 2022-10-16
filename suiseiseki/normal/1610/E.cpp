#include <cstdio>
#include <algorithm>
const int Maxn=200000;
int n;
int a[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i>1&&a[i]==a[i-1]){
			continue;
		}
		int pos=i+1;
		int num=2;
		while(pos<=n){
			pos=std::lower_bound(a+1+pos,a+1+n,a[pos]+a[pos]-a[i])-a;
			if(pos>n){
				break;
			}
			num++;
		}
		ans=std::max(ans,num);
	}
	printf("%d\n",n-ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}