#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n;
int vis[10010],p[10010];
int query(int x){
	printf("? %d\n",x);fflush(stdout);
	return read();
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) vis[i]=0,p[i]=i;
		for(int i=1;i<=n;++i) if(!vis[i]){
			vector<int>cir;
			int ls=0;
			while(1){
				int t=query(i);p[ls]=t;if(vis[t]) break ;ls=t;vis[t]=1;
			}
		}
		printf("! ");for(int i=1;i<=n;++i) printf("%d ",p[i]);
		fflush(stdout);
	}
}