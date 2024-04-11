#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Mod 1000000007
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
int s1(int n){n%=Mod;return n*(n+1)/2%Mod;}
int n,m;
signed main(){
	n=read();m=read();
	int ans=n%Mod*(m%Mod)%Mod;
	m=min(m,n);
	for(int l=1,r;l<=m;l=r+1){
		r=min(n/(n/l),m);
		int tmp=(n/l)%Mod*(s1(r)-s1(l-1)+Mod)%Mod;
		ans=(ans+Mod-tmp)%Mod;
	}
	printf("%lld\n",ans);
	return 0;
}