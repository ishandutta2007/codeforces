#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll ans,n,a[200009],b[200009],mod=998244353;
int main(){
	cin>>n;
	f(i,0,n){
		cin>>a[i];
		a[i]*=(i+1)*(n-i);
	}
	f(i,0,n) cin>>b[i];
	sort(a,a+n);
	sort(b,b+n);
	f(i,0,n){
		a[i]=a[i]%mod;
		b[n-i-1]=b[n-i-1]%mod;
		ans=(ans+((a[i]*b[n-i-1])%mod))%mod;
	}
	cout<<ans;
}