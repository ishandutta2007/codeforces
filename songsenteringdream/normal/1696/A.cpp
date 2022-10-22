#include<cstdio>
#include<iostream>
using namespace std;
int T,n,z,a,ans;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),ans=0)
		for(scanf("%d%d",&n,&z);n--;ans=max(ans,a|z)) scanf("%d",&a);
	return 0;
}