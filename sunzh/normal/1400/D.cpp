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
int n;
int a[3010];
int cnt[10000010];
int main(){
	int T=read();
	while(T--){
		n=read();
		long long ans=0;
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cnt[i*n+j]=0; 
		for(int j=n-2;j>1;--j){
			int k=j+1;
			for(int l=k+1;l<=n;++l){
				++cnt[a[k]*n+a[l]];
			}
			for(int i=1;i<j;++i) ans+=cnt[a[i]*n+a[j]];
		}
		printf("%lld\n",ans);
	}
}