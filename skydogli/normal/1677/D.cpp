#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 1000005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
#define Mod 998244353 
int n,k,T;
int a[MN];
signed main(){
	T=read();
	while(T--){
		n=read(),k=read();
		int GG=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(i>=n-k+1&&a[i]>0)GG=1;
		}
		if(GG){
			puts("0");
			continue;
		}
		int ans=1;
		for(int i=1;i<=k;++i)ans=ans*i%Mod;
		for(int i=1;i<=n-k;++i){
			if(!a[i])ans=ans*(k+1)%Mod;
			else if(a[i]==-1)ans=ans*(i+k)%Mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}