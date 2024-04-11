#include <bits/stdc++.h>

const int max_N=5000;

int n,ans;

int a[max_N+21];//b0 ^ bi

int b[max_N+21],p[max_N+21];

int c[max_N+21];//pi ^ bi

std::vector<int>ans1;

bool vis[max_N+21];

inline void check(int x){
	for(int i=0;i<n;++i)vis[i]=0;
	for(int i=0;i<n;++i)b[i]=a[i]^x;
	for(int i=0;i<n;++i){
		if(b[i]>=n||vis[b[i]])return;
		vis[b[i]]=1,p[b[i]]=i;	
	}
	for(int i=0;i<n;++i)
		if(c[i]!=(b[i]^p[i]))return;
	if(++ans==1){
		for(int i=0;i<n;++i)ans1.push_back(p[i]);	
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0,x,y;i<n;++i){
		printf("? %d %d\n",i,i);
		fflush(stdout);
		scanf("%d",&x);
		c[i]=x;
		if(i+1==n)break;
		printf("? %d %d\n",i,i+1);
		fflush(stdout);
		scanf("%d",&y);
		a[i+1]=x^y^a[i];
	}
	for(int i=0;i<n;++i)check(i);
	puts("!");
	printf("%d\n",ans);
	for(int i=0;i<n;++i)printf("%d%c",ans1[i]," \n"[i+1==n]);
	return 0;	
}