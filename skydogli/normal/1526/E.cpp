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
#define MN 400005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
#define Mod 998244353
int n,k,sa[MN],rk[MN];
int fac[MN],dfac[MN],inv[MN];
int C(int m,int n){
	if(m<n)return 0;
	return fac[m]*dfac[n]%Mod*dfac[m-n]%Mod;
}
signed main(){
	n=read();k=read();
	fac[0]=dfac[0]=fac[1]=dfac[1]=inv[1]=1;
	for(int i=2;i<=n+k;++i){
		fac[i]=fac[i-1]*i%Mod;
		inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
		dfac[i]=dfac[i-1]*inv[i]%Mod;
	}
	for(int i=1;i<=n;++i){
		sa[i]=read()+1;
		rk[sa[i]]=i;
	}
	int p=0,q=1;
	for(int i=1;i<n;++i)
		if(rk[sa[i]+1]<rk[sa[i+1]+1])p++;
		else q++;
	cout<<C(k+p,p+q)<<endl;
	return 0;
}