#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
long long x[200003],y,s,a[200003],f[200003],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y>>s;
		int nw=lower_bound(x,x+i,y)-x;
		a[i]=(f[i-1]-f[max(nw,1)-1]+mod+x[i]-y)%mod;
		f[i]=(f[i-1]+a[i])%mod;
		if(s)ans=(ans+a[i])%mod;
	}cout<<(ans+x[n]+1)%mod;
}