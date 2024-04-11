#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const int o=2e5+10;
int T,n,x,a[o],mx,mn;long long ans;
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=0){
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		mn=mx=a[n];
		for(int i=1;i<n;++i) ans+=abs(a[i]-a[i+1]),mn=min(mn,a[i]),mx=max(mx,a[i]);
		if(1<mn) ans+=min((mn-1)*(1+(a[1]!=mn&&a[n]!=mn)),min(a[n]-1,a[1]-1));
		if(mx<x) ans+=min((x-mx)*(1+(a[1]!=mx&&a[n]!=mx)),min(x-a[n],x-a[1]));
	}
	return 0;
}