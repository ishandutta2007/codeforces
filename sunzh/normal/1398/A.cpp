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
int n;
int a[500010];
int main(){
	T=read();
	while(T--){
		n=read();
		a[0]=0x3f3f3f3f;a[n+1]=0;a[n+2]=0x3f3f3f3f;
		int maxn=n+1,minn=0,nxt=n+2;
		for(int i=1;i<=n;++i) {
			a[i]=read();
			if(a[i]>a[maxn]) maxn=i;
			if(a[i]<a[minn]){
				nxt=minn;minn=i;
			}
			else if(a[i]<a[nxt]||a[i]==a[minn]){
				nxt=i;
			}
		}
		if(a[minn]+a[nxt]<=a[maxn]){
			int opt[4]={0,minn,nxt,maxn};
			sort(opt+1,opt+4);
			printf("%d %d %d\n",opt[1],opt[2],opt[3]);
		}
		else printf("-1\n");
	}
	return 0;
}