#include<bits/stdc++.h>
using namespace std;
int n,d,e;
int main(){
	scanf("%d%d%d",&n,&d,&e);
	int ans=n;
	for(int i=0;i<=n/d;++i){
		ans=min(ans,(n-i*d)%(e*5));
	}
	printf("%d",ans);
	return 0;
}