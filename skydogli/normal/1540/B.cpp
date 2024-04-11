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
#define MN 405
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
#define Mod 1000000007
int ksm(int a,int x){
	int ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
int T,n,m;
int a[MN],fac[MN],dfac[MN],inv[MN],pw[MN],ipw[MN],tag[MN][MN];
vc e[MN];
int C(int m,int n){
	if(m<n)return 0;
	return fac[m]*dfac[n]%Mod*dfac[m-n]%Mod;
}
int fa[MN],dep[MN];
void dfs(int x){
	dep[x]=dep[fa[x]]+1;
	for(auto v:e[x]){
		if(fa[x]==v)continue;
		fa[v]=x;dfs(v);
	}
}
int LCA(int x,int y){
	while(x!=y){
		if(dep[x]<dep[y])y=fa[y];
		else x=fa[x];
	}
	return x;
}
signed main(){
	n=read();
	fac[0]=dfac[0]=fac[1]=dfac[1]=inv[1]=1;
	pw[0]=1;for(int i=1;i<=n;++i)pw[i]=pw[i-1]*2%Mod;
	ipw[0]=1;for(int i=1;i<=n;++i)ipw[i]=ksm(pw[i],Mod-2);
	for(int i=2;i<=n;++i){
		fac[i]=fac[i-1]*i%Mod;
		inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
		dfac[i]=dfac[i-1]*inv[i]%Mod;
	}
	for(int i=1;i<n;++i){
//		int  x=n-i+1;int y=n-i;
		int x=read(),y=read();
		e[x].pb(y);
		e[y].pb(x);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		fa[i]=0;dfs(i);
//		cerr<<"rt "<<i<<endl;
		for(int i=1;i<=n;++i)
			for(int j=1;j<i;++j){
				int g=LCA(i,j);
				int x=dep[i]-dep[g],y=dep[j]-dep[g];
				if(x&&y){
					tag[x][y]++;
				}
				else if(!x)ans++;
			}
	}
	for(int x=1;x<=n;++x)
		for(int y=1;y<=n;++y){	
			for(int i=1;i<=x+y-1;++i)
				ans=(ans+C(i-1,x-1)*ipw[i]%Mod*tag[x][y])%Mod;
		}
	printf("%lld\n",ans*ksm(n,Mod-2)%Mod);
	return 0;
}