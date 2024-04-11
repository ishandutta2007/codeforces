#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=3e5+10;
ll n,k,a[maxn],sum[maxn],ans,st=1,en=-1;//1 inexed
int main(){
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++){
		ll l=i,r=n;
		while(l<=r){
			ll mid=(l+r)/2;
			if((mid-i+1)-(sum[mid]-sum[i-1])<=k){
				if(mid-i+1>ans){
					ans=mid-i+1;
					st=i;
					en=mid;
				}
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
	}
	cout<<ans<<endl;
	if(st<=en){
		for(ll i=1;i<st;i++)cout<<a[i]<<" ";
		for(ll i=st;i<=en;i++)cout<<1<<" ";
		for(ll i=en+1;i<=n;i++)cout<<a[i]<<" ";
	}
	else{
		for(ll i=1;i<=n;i++)cout<<a[i]<<" ";
	}
}