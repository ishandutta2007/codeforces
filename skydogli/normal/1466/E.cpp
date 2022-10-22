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
#define MN 500005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
int T,n,m;
int a[MN];
char ch[MN];
int tax[65];
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=0;i<=60;++i)tax[i]=0;
		for(int i=1;i<=n;++i){
			a[i]=read();
			for(int j=0;j<60;++j)
				if((a[i]>>j)&1)tax[j]++;
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			int tot=0;
			for(int j=0;j<=60;++j)
				if((a[i]>>j)&1ll)(tot+=(1ll<<j)%Mod*(tax[j]))%=Mod;
			for(int j=0;j<=60;++j){
				if((a[i]>>j)&1ll)
					ans=(ans+(1ll<<j)%Mod*tot%Mod*(n))%Mod;
				else 
					ans=(ans+(1ll<<j)%Mod*tot%Mod*(tax[j]))%Mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}