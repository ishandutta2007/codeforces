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
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
#define Mod 998244353
int T,n,m,fac[MN],dfac[MN],inv[MN];;
char ch[MN];
int C(int m,int n){
	if(m<n)return 0;
	return fac[m]*dfac[n]%Mod*dfac[m-n]%Mod;
}
signed main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",ch+1);
		fac[0]=dfac[0]=fac[1]=dfac[1]=inv[1]=1;
		for(int i=2;i<=n;++i){
			fac[i]=fac[i-1]*i%Mod;
			inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
			dfac[i]=dfac[i-1]*inv[i]%Mod;
		}
		int t=0,r=0;
		for(int i=1;i<=n;++i){
			if(ch[i]=='1'&&ch[i+1]=='1'){t++;i++;}
			else if(ch[i]=='1')r++;
		}
		printf("%lld\n",C(n-t-r,t));
	}
	return 0;
}