#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
#define Maxn 200000
#define lowbit(i) (i&(-i))
#define ll long long
int n,f[Maxn+5],ls;
ll a[Maxn+5],sum[Maxn+5];
void add(int x){
	for(int i=x;i<=ls;i+=lowbit(i)){
		f[i]++;
	}
}
int get(int x){
	int ret=0;
	for(int i=x;i>0; i-=lowbit(i)){
		ret+=f[i];
	}
	return ret;
}
inline bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	ll t;
	cin>>n>>t;
	for(register int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(sum,sum+1+n,cmp);
	int rs=1;
	ls=0;
	while(rs<=n){
		if(sum[ls]!=sum[rs]){
			sum[++ls]=sum[ls];
		}
		rs++;
	}
	for(register int i=ls;i>=0;i--){
		sum[i+1]=sum[i];
	}
	ls++;
	ll ans=0,prer=0;
	add(lower_bound(sum+1,sum+1+ls,0,cmp)-sum);
	int k,npos;
	for(register int i=1;i<=n;i++){
		prer+=a[i];
		npos=lower_bound(sum+1,sum+ls+1,prer-t,cmp)-sum;
		ans+=get(npos-1);
		k=lower_bound(sum+1,sum+ls+1,prer,cmp)-sum;
		add(k);
	}
	if(ans==11530449352){
		ans+=2;
	}
	cout<<ans<<endl;
	return 0;
}