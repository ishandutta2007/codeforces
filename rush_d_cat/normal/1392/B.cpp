#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n; LL k,a[N];
void solve(){
	LL mx=*max_element(a+1,a+1+n);
	for(int i=1;i<=n;i++) a[i]=mx-a[i];
}
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(k>=1) solve();
		if(k>=2) solve();
		if(k>=3) {
			if(k&1) solve();
		}
		for(int i=1;i<=n;i++)printf("%lld ", a[i]);
		printf("\n");
	}
}