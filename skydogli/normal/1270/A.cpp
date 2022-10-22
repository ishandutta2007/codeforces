#include<bits/stdc++.h>
using namespace std;
int T,n,m;
int main(){
	scanf("%d",&T);
	while(T--){
		int tot;
		scanf("%d%d%d",&tot,&n,&m);
		int A=0,B=0,a;
		for(int i=1;i<=n;++i){scanf("%d",&a);A=max(A,a);}
		for(int i=1;i<=m;++i){scanf("%d",&a);B=max(B,a);}
		puts(A>B?"YES":"NO");
	}
	return 0;
}