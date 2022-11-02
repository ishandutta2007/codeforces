#include <bits/stdc++.h>

const int max_N=3e5;

int n,f[max_N+21],siz[max_N+21];

bool vis[max_N+21];

int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);	
}

inline void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	if(siz[x]<siz[y])std::swap(x,y);
	f[y]=x,siz[x]+=siz[y];	
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)f[i]=i,siz[i]=1;
	printf("%d",1);
	for(int i=1,x;i<=n;++i){
		scanf("%d",&x);
		vis[x]=1;
		if(vis[x-1])merge(x,x-1);
		if(vis[x+1])merge(x,x+1);
		int tmp=vis[n]?siz[find(n)]:0;
		printf(" %d",i-tmp+1);
	}
	puts("");
	return 0;
}