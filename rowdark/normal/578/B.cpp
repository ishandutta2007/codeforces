#include<stdio.h>
#include<iostream>
#include<algorithm>
int n;
int a[200001];
int pre[200001];
int suf[200001];
long long ans;
int k,x;
long long g=1;
int main(){
	scanf("%d%d%d",&n,&k,&x);
	while(k--) g*=x;
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=1;i<=n;++i){
		pre[i]=pre[i-1]|a[i];
	}
	for(int i=n;i;--i){
		suf[i]=suf[i+1]|a[i];
	}
	for(int i=1;i<=n;++i){
		ans=std::max(ans,(g*a[i])|pre[i-1]|suf[i+1]);
	}
	std::cout<<ans<<std::endl;
	return 0;
}