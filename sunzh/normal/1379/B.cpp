#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){ if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
	return x*f;
}
int T;
int l,r,m;
signed main(){
	T=read();
	while(T--){
		l=read(),r=read(),m=read();
		for(int i=l;i<=r;++i){
			int s1=m-(m/i)*i;
			int s2=((m/i)+1)*i-m;
			if(m>=i&&s1<=r-l){
				printf("%lld %lld %lld\n",i,r,r-s1);
				break ;
			}
			if(s2<=r-l){
				printf("%lld %lld %lld\n",i,r-s2,r);
				break ;
			}
		}
	}
	return 0;
}