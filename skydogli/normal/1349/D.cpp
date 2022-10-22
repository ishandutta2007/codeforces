#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Mod 998244353
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 300005
int n,a[MN],inv[MN],f[MN];
signed main(){
	n=read();
	int m=0;
	for(int i=1;i<=n;++i){
		a[i]=read();
		m+=a[i];
	}
	inv[1]=1;for(int i=2;i<=m;++i)inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	f[0]=f[1]=0;
	for(int i=1;i<=m;++i){
		int tmp=(n-1)*inv[m-i]%Mod;
		f[i+1]=((m*tmp-(n-2)+Mod)%Mod*f[i]-i*tmp%Mod*(f[i-1]-1+Mod)%Mod+Mod)%Mod;
	}
	int sum=0;
	for(int i=1;i<=n;++i)sum+=f[a[i]];
	sum%=Mod;
	printf("%lld\n",(f[m]-sum+Mod)%Mod);
	return 0;
}