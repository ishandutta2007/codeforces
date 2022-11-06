#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int pre[2001000],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		pre[x]=x;
	}
	for(int i=1;i<=2000000;++i){
		if(pre[i]==0) pre[i]=pre[i-1];
	}
	int ans=0;
	for(int i=1;i<=1000000;++i) if(pre[i]==i){
		for(int j=i;j<=1000000;j+=i){
			int k=pre[j+i-1];
			ans=max(ans,k-j);
		}
	}
	printf("%d\n",ans);
	return 0;
}