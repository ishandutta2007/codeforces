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
long long ans;
long long a[200010];
int main(){
	T=read();
	while(T--){
		ans=0;
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<n;++i) ans+=max(0ll,a[i]-a[i+1]); 
		printf("%lld\n",ans);
	}
	return 0;
}