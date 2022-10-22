#include<bits/stdc++.h>
using namespace std;
#define MN 400005
int T,n,p[MN];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&p[i]);
		}
		int g=0,b=0,s=0;
		for(int i=2;i<=n;++i){
			if(p[i]!=p[i-1]){
				g=i-1;
				break;
			}
		} 
		if(!g){
			puts("0 0 0");
			continue;
		}
		for(int i=g+2;i<=n;++i){
			if(p[i]!=p[i-1]&&i-1-g>g){
				s=i-1-g;
				break;
			}
		}
		if(!s){
			puts("0 0 0");
			continue;
		}
		for(int i=g+s+1;i<=n/2+1;++i){
			if(p[i]!=p[i-1]) b=i-1-g-s;
		}
		if(g>=b)puts("0 0 0");
		else printf("%d %d %d\n",g,s,b);
	}
	return 0;
}