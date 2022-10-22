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
int p[4010];
int opt[4010];
int cnt;
int q[4010],pos[4010];
bool f[4010];
int main(){
	T=read();
	while(T--){
		memset(f,0,sizeof(f));
		n=read();
		cnt=0;
		int h=1,t=0;
		for(int i=1;i<=2*n;++i) p[i]=read();
		p[2*n+1]=0x7f7f7f7f;
		for(int i=1;i<=2*n+1;++i){
			while(h<=t&&p[q[t]]<p[i]){
				pos[q[t]]=i;--t;
			}
			q[++t]=i;
		}
		int i=1;
		while(i<=2*n){
			opt[++cnt]=pos[i]-i;
			i=pos[i];
		}
		f[0]=1;
		for(int i=1;i<=cnt;++i)
			for(int j=n;j>=opt[i];--j) f[j]=f[j]|f[j-opt[i]];
		if(f[n]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}