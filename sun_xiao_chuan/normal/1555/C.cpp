#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m;
ll a[200500],b[200500],res;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		a[n+1]=0;
		for(i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(i=1;i<=n;i++){
			scanf("%lld",&b[i]);
			b[i]+=b[i-1];
		}
		for(i=n;i>=1;i--){
			a[i]+=a[i+1];
		}
		res=1e18;
		for(i=1;i<=n;i++){
			res=min(res,max(a[i+1],b[i-1]));
		}
		printf("%lld\n",res);
		
	}
}