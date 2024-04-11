#include<bits/stdc++.h>
using namespace std;
#define MN 200005
int T,n,m,a[MN];
int main(){
	scanf("%d",&T);
	while(T--){
		int tot;
		scanf("%d",&n);
		bool t=0;
		int Min=1e9,p=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(i>1&&abs(a[i]-a[i-1])>1&&!t) {puts("YES");printf("%d %d\n",i-1,i);t=1;} 
		}
		if(!t)puts("NO");
	}
	return 0;
}