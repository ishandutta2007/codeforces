#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define Mod 1000000007
ll f[100005];
ll sum[100005];
struct Seg{
	int s,t;
	friend bool operator <(Seg p,Seg q){
		return p.t<q.t;
	}
}a[100005];
int v[100005];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a[i].s,&a[i].t);
		v[i]=a[i].t;
	}
	sort(a+1,a+1+m);
	sort(v+1,v+1+m);
	int s,t;
	for(int i=1;i<=m;i++){
		s=lower_bound(v+1,v+1+m,a[i].s)-v;
		t=lower_bound(v+1,v+1+m,a[i].t)-v;
		f[i]=(sum[t]-sum[s]+Mod)%Mod;
		if(a[i].s==0){
			f[i]++;
		}
		sum[i+1]=sum[i]+f[i];
		sum[i+1]%=Mod;
	}
	ll ans=0;
	for(int i=1;i<=m;i++){
		if(a[i].t==n){
			ans+=f[i];
			ans%=Mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}