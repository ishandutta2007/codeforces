#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,h[105];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;++i){
			scanf("%d",&h[i]);
		}
		int now=m,ok=1;
		for(int i=1;i<n;++i){
			if(h[i+1]-h[i]<k){now+=h[i]-max(0,h[i+1]-k);h[i]=h[i+1]-k;}
			if(h[i+1]-h[i]>k){now-=(h[i+1]-k)-h[i];h[i]=h[i+1]-k;}
			if(now<0){ok=0;break;}
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}