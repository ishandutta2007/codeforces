#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int T;
int p,f;
int cnts,cntw;
int s,w;
int main(){
	T=read();
	while(T--){
		p=read(),f=read();
		cnts=read(),cntw=read();
		s=read(),w=read();
		if(s>w){
			swap(cnts,cntw);swap(s,w);
		}
		int ans=0;
		for(int i=0;i<=cnts;++i){
			if(i*s>p) break ;
			int cnt=min(f/s,cnts-i);
			int lft=f-cnt*s;
			ans=max(ans,i+cnt+min((p-i*s)/w+lft/w,cntw));
		}
		printf("%d\n",ans);
	}
	return 0;
}