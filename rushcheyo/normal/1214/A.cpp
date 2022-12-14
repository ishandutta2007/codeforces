#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,d,e;
	scanf("%d%d%d",&n,&d,&e),e*=5;
	int ans=1<<30;
	for(int i=0;i<=n/d;++i)ans=min(ans,(n-i*d)%e);
	printf("%d\n",ans);
}