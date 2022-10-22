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
#define vc vector
#define Mod 998244353
int T,n,m;
int f[MN],g[MN],G[MN];
const int inv2=(Mod+1)/2,inv3=(Mod+1)/3,inv6=inv2*inv3%Mod;
int s1(int n){return n*(n+1)/2%Mod;}
int s2(int n){return n*(n+1)%Mod*(2*n+1)%Mod*inv6%Mod;}
signed main(){
	n=read();
	if(n==1){puts("5");return 0;}
	int tmp=1;
	f[0]=g[0]=1;
	for(int i=1;i<=n;++i){
		f[i]=(f[i-1]+f[i-1]*(i==1?0:g[i-2])+f[i-1]*(f[i-1]+1)/2)%Mod;
		g[i]=(g[i-1]+f[i])%Mod;
		G[i]=(f[i]-f[i-1]+Mod)%Mod;
	}
	int res=((f[n]+f[n-1]*s1(g[n-2])+s1(f[n-1])*g[n-2]%Mod)*2+s2(f[n-1])+s1(f[n-1])-1)%Mod;
//	cerr<<"res "<<res<<endl;
	for(int i=0;i<n;++i)res=(res+(f[i]-1)*G[n-i-1])%Mod;
	cout<<res<<endl;
	return 0;
}