#include <bits/stdc++.h>

template<typename T>inline void read(T&x){
	register int f,c; f=1; 
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	for(x=c-48;isdigit(c=getchar());x=x*10+c-48);
	x*=f;
}

const int max_N = 1e3 + 21;

int n,deg[max_N],p[max_N],cnt[max_N];

int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		scanf("%d",p+i);
		++deg[p[i]];
	}
	for(int i=2;i<=n;++i)
		if(!deg[i])++cnt[p[i]];
	for(int i=1;i<=n;++i)
		if(deg[i]&&cnt[i]<3){
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}