#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int T,n,x,a[o],ans,l,r;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),ans=0){
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		l=a[1]-x;r=a[1]+x;
		for(int i=2;i<=n;++i){
			l=max(l,a[i]-x);r=min(r,a[i]+x);
			if(l>r) ++ans,l=a[i]-x,r=a[i]+x;
		}
	}
	return 0;
}