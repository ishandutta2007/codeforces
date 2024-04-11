#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){ if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
	return x*f;
}
int T;
int n;
bool vis[100];
int main(){
	T=read();
	while(T--){
		n=read();
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=2*n;++i){
			int x=read();
			if(vis[x]) continue ;
			vis[x]=1;
			printf("%d ",x);
		}
		printf("\n");
	}
	return 0;
}