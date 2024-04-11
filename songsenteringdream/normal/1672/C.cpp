#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int T,n,a[o],mx,mn;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);mx=0;mn=n+1;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<n;++i) if(a[i]==a[i+1]) mx=max(mx,i),mn=min(mn,i);
		if(mx<=mn) printf("0\n");
		else if(mx==mn+1) printf("1\n");
		else printf("%d\n",mx-mn-1);
	}
	return 0;
}