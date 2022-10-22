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
#define Mod 1000000007
int T,n,m;
const int N=2e6;
int inv[N+N+5];
#define mn (1<<14|5)
int f[mn],g[mn][15],h[mn];
int cnt[mn],a[15];
int sgn(int n){if(n&1)return (Mod-1);return 1;}
signed main(){
	n=read();
	inv[1]=1;for(int i=2;i<=N+N;++i)inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	for(int i=1;i<=n;++i)a[i]=read();
	for(int st=0;st<(1<<n);++st){
		cnt[st]=(cnt[st>>1]+(st&1));
		for(int i=1;i<=n;++i){
			if((st>>i-1)&1)continue;
			g[st][i]=1;
			for(int j=1;j<=n;++j)
				if((st>>j-1)&1)g[st][i]=g[st][i]*inv[a[j]+a[i]]%Mod*a[j]%Mod;
		}
	}
	for(int st=1;st<(1<<n);++st){
		h[st]=1;
		for(int u=(st-1)&st;u;u=(u-1)&st){
//			if((st&(-st))!=(u&(-u)))continue;
			int A=1,B=1;
			for(int j=1;j<=n;++j){
				if((u>>j-1)&1)A=g[st-u][j]*A%Mod;
				if(((st-u)>>j-1)&1)B=g[u][j]*B%Mod;
			}
			A=0;
	//		cerr<<"fk "<<st<<" "<<u<<": "<<sgn(cnt[st-u])<<" "<<A+B<<" "<<h[u]<<endl;
			h[st]=(h[st]-h[u]*(A+B)%Mod+Mod)%Mod;
		}
//		cerr<<"h "<<st<<": "<<h[st]<<endl;
	}
	int ans=0;
	for(int i=1;i<=n;++i){
	//	cerr<<"FK "<<i<<endl;
		for(int j=0;j<(1<<n);++j)f[j]=0;
//		f[1<<i-1]=1;
		for(int st=(1<<i-1);st<(1<<n);++st){
			if(!((st>>i-1)&1))continue;
			f[st]=(f[st]+h[st])%Mod;
			int w=((1<<n)-1)^st;
			for(int u=w;u;u=(u-1)&w){	
				int to=st|u,r=1;
				for(int j=1;j<=n;++j)
					if((u>>j-1)&1)r=r*g[st][j]%Mod;
//				cerr<<st<<" "<<u<<": "<<f[st]<<" "<<r<<" "<<h[u]<<endl;
				f[to]=(f[to]+r*f[st]%Mod*h[u])%Mod;
				if(!u)break;
			}
		//	cerr<<st<<": "<<f[st]<<endl;
		}
//		cerr<<"f "<<i<<": "<<f[(1<<n)-1]<<endl;
		ans+=f[(1<<n)-1];
	}
	printf("%lld\n",ans%Mod);
	return 0;
}