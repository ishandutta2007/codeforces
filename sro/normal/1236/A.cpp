#include <bits/stdc++.h>
using namespace std;

int a,b,c;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&c);
		int fx=min(b,c/2);
		int ans=fx*3;
		b-=fx;
		fx=min(a,b/2);
		ans+=fx*3;
		printf("%d\n",ans);
	}
	return 0;
}