#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<set>
#define LL long long
#define M 200020
using namespace std;
int read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
set<int> S;
int n,m,tot,fs[M],nt[M<<1],to[M<<1],ind[M],tmp,p[M];
inline void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),memset(fs,-1,sizeof(fs));
	while(m--){
		int x=read(),y=read();
		link(x,y),link(y,x);
	}
	S.insert(1);
	for(int i=1;i<=n;i++){
		int x=(*(S.begin())); ind[p[i]=x]=1,S.erase(S.begin());
		for(int i=fs[x];i!=-1;i=nt[i]) if(!ind[to[i]]) S.insert(to[i]);
	}
	for(int i=1;i<=n;i++) printf("%d%c",p[i],i<n?' ':'\n');
	return 0;
}