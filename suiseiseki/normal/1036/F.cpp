#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const ll Maxn=1000000000000000000ll;
ll f[1004005];
bool check(ll x){
	ll now=(ll)sqrt(x*1.0);
	return now*now<x;
}
int main(){
	ll x;
	int len=0;
	for(ll i=2;i<=1000000;i++){
		x=i*i;
		while(x<=Maxn/i){
			x*=i;
			if(check(x)){
				f[++len]=x;
			}
		}
	}
	sort(f+1,f+1+len);
	len=(int)(unique(f+1,f+1+len)-f-1);
	int t;
	scanf("%d",&t);
	ll n;
	while(t--){
		cin>>n;
		x=upper_bound(f+1,f+1+len,n)-f-1;
		cout<<n-x-(ll)sqrt(n*1.0)<<endl;
	}
	return 0;
}