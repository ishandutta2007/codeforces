#include<bits/stdc++.h>
using namespace std;
int n,a[100005],fh,zero;
long long ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==0) zero++;
		if(a[i]>=1) ans+=(long long)a[i]-1ll;
		if(a[i]<=-1) ans+=(-1ll-(long long)a[i]),fh^=1;
	}
	if(!fh||zero) printf("%I64d",ans+(long long)zero);
		else printf("%I64d",ans+2);
	return 0;
}