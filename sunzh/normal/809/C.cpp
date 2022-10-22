#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int T;
int a,b,c,d,k;
const int mod=1e9+7;
int f[2][2][2][2],g[2][2][2][2];
bool flag;
int sol(int x,int y,int z){
	if(x<0||y<0||z<0) return 0;
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	f[flag][1][1][1]=1;
	for(int i=31;i>=1;--i){
		flag^=1;
		int s1=((x>>i-1)&1),s2=((y>>i-1)&1),s3=((z>>i-1)&1);
		for(int _=0;_<=1;++_){
			for(int __=0;__<=1;++__){
				for(int ___=0;___<=1;++___){
					for(int X=0;X<=(s1|(!_));++X){
						for(int Y=0;Y<=(s2|(!__));++Y){
							if((X^Y)>s3&&___) continue ;
							f[flag][_&(X==s1)][__&(Y==s2)][___&((X^Y)==s3)]+=f[flag^1][_][__][___];
							if(f[flag][_&(X==s1)][__&(Y==s2)][___&((X^Y)==s3)]>mod) f[flag][_&(X==s1)][__&(Y==s2)][___&((X^Y)==s3)]-=mod;
							g[flag][_&(X==s1)][__&(Y==s2)][___&((X^Y)==s3)]=(g[flag][_&(X==s1)][__&(Y==s2)][___&((X^Y)==s3)]+g[flag^1][_][__][___]+1ll*f[flag^1][_][__][___]*(((X^Y)&1)<<i-1)%mod)%mod;
						}
					}
					f[flag^1][_][__][___]=g[flag^1][_][__][___]=0;
				}
			}
		}
	}
	int res=0;
	for(int _=0;_<=1;++_)
		for(int __=0;__<=1;++__)
			for(int ___=0;___<=1;++___){
				res+=f[flag][_][__][___]+g[flag][_][__][___];
				if(res>mod) res-=mod;if(res>mod) res-=mod;
			}
	return res;
}
signed main(){
	T=read();
	while(T--){
		int ans=0;
		a=read(),b=read(),c=read(),d=read(),k=read();
		printf("%d\n",(sol(c-1,d-1,k-1)-sol(c-1,b-2,k-1)-sol(a-2,d-1,k-1)+sol(a-2,b-2,k-1)+mod+mod)%mod);
	}
	return 0;
}