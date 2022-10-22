#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int T,n,a[o],mx,mn;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);mx=0;mn=1e9;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),mx=max(mx,a[i]),mn=min(mn,a[i]);
		for(int i=1;i<=n;++i) if(a[i]==mn){printf("%d ",i);break;}
		for(int i=1;i<=n;++i) if(a[i]==mx){printf("%d\n",i);break;}
	}
	return 0;
}