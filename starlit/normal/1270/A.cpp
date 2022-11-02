#include<bits/stdc++.h>
using namespace std;
int T,n,m,x,a,b;
int main(){
	for(scanf("%d",&T);T--;){
		a=b=0;
		scanf("%*d%d%d",&n,&m);
		for(;n--;)
		scanf("%d",&x),a=max(a,x);
		for(;m--;)
		scanf("%d",&x),b=max(b,x);
		puts(a<b?"NO":"YES");
	}
}