#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=5e5,e=4e7+4;
int n,a[N],md[e],sum[e];
ll ans;
ll g(ll l,ll r){
	if(r<l) return 0;
	if(l==0) return sum[r];
	if(l<0) cout<<"SHIt";
	return (sum[r]-sum[l-1])%2;
}
ll solve(ll x){
	f(i,0,x) sum[i]=md[i]=0;
	ll ans=0;
	f(i,0,n)
		md[a[i]%x]++;
	sum[0]=md[0];
	f(i,1,x) sum[i]=md[i]+sum[i-1];
	f(i,1,x){
		if(g(max(1ll*0,x/2-i),min(i-1,x-1-i))%2==1 && md[i]%2==1)
			ans=(ans+1)%2;
		if(g(min(x,(x+(x/2))-i),min(i-1,2*x-1-i))%2==1 && md[i]%2==1)
			ans=(ans+1)%2;
		if((i*2)%x>=x/2 && md[i]%4>=2){
			ans=(ans+1)%2;
		}
	}
	return ans%2;
}
int xr(int x,int y){
	int tvn=1,k=0;
	while(x || y){
		k+=(x%2+y%2==1)*tvn;
		tvn*=2;
		x/=2,y/=2;
	}
	return k;
}
int main(){
	srand(time(NULL));
	ans=0;
	cin>>n;
	f(i,0,n)
		cin>>a[i];
	for(int j=2;j<=e;j*=2){
		ans+=solve(j)*j/2;
	}
	cout<<ans<<endl;
	ans=0;
}