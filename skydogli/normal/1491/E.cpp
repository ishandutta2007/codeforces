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
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid ((l+r)>>1)
namespace geometry{
#define db long double
	const db eps=1e-14;
	const db inf=1e13;
	struct P{
		db x,y;	
		P() {}
		P(db X,db Y){
			x=X;y=Y;
		}
		db len(){return sqrt(x*x+y*y);}
	};
	P operator +(P a,P b){return P(a.x+b.x,a.y+b.y);}
	P operator -(P a,P b){return P(a.x-b.x,a.y-b.y);}
	P operator *(P a,db b){return P(a.x*b,a.y*b);}
	db operator ^(P a,P b){return a.x*b.y-a.y*b.x;}	
	bool onr(P a,P b){//b in a's right
		return (a^b)<0;
	}
	struct Line{
		P a,b,vec;
		db ang;
		Line(P A=P(0,0),P B=P(0,0)){
			a=A;b=B;vec=b-a;
			ang=atan2(vec.y,vec.x);
		}
		bool friend operator<(Line a,Line b){
	//		if(fabs(a.ang-b.ang)<eps) return a.vec.len()<b.vec.len();
			return a.ang<b.ang;
		}
	};
	P getp(Line a,Line b){//
		db ABC=a.vec^(b.a-a.a),ABD=(b.b-a.a)^a.vec;
		db k=ABC/(ABC+ABD);
		return b.a+(b.vec*k);
	}
#undef db
};
namespace math{
	const int Mod = 998244353;
	int ksm(int a,int x){
		int ans=1,w=a;
		while(x){
			if(x&1)ans=ans*w%Mod;
			w=w*w%Mod;
			x>>=1;
		}
		return ans;
	}
	int fac[MN],dfac[MN],inv[MN];
	int C(int m,int n){
		if(m<n)return 0;
		return fac[m]*dfac[n]%Mod*dfac[m-n]%Mod;
	}
	void init(int N){
		fac[0]=dfac[0]=fac[1]=dfac[1]=inv[1]=1;	
		for(int i=2;i<=N;++i){
			fac[i]=fac[i-1]*i%Mod;
			inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
			dfac[i]=dfac[i-1]*inv[i]%Mod;
		}
	}
}
//using namespace geometry;
//using namespace math;
int T,n,m;
int a[MN];
int fib[55];
vector<int>e[MN];
int fa[MN],siz[MN],w[MN],tot;
int rt,vis[MN];
int K,tmp;
void dfs(int x){
	siz[x]=1;w[x]=0;
	for(auto v:e[x]){
		if(vis[v]||fa[x]==v)continue;
		fa[v]=x;
		dfs(v);
		siz[x]+=siz[v];
		if(siz[w[x]]<siz[v])w[x]=v;
	}
	if(max(siz[w[x]],tot-siz[x])<=tot/2)rt=x;
	if(siz[x]==fib[K-2]) tmp=x;
//	cerr<<"dfs: "<<x<<" "<<rt<<" siz: "<<siz[x]<<" "<<fib[K-2]<<endl;
}
bool ok;
void work(int x,int n,int k){
	if(n==1){ok=1;return;}
	rt=0;fa[x]=0;tot=n;K=k;dfs(x);
	int t=rt;fa[rt]=0;tmp=0;dfs(rt);
//	cerr<<x<<" "<<n<<" "<<k<<" rt:"<<rt<<" tmp: "<<tmp<<endl;
	if(!tmp){ok=0;return;}
	int y=fa[tmp],xx=tmp;
	vis[y]=1;
	ok=0;
	work(tmp,fib[k-2],k-2);
	if(!ok){ok=0;return;}
	ok=0;
	vis[xx]=1;vis[y]=0;
	work(y,fib[k-1],k-1);
	if(ok){ok=1;return;}
}
signed main(){
	n=read();
	if(n==1){puts("YES");return 0;}
	fib[0]=fib[1]=1;
	int ok=0;
	for(int i=2;i<=30;++i){
		fib[i]=fib[i-1]+fib[i-2];	
		if(fib[i]==n)ok=i;
	}
	if(!ok){puts("NO");return 0;}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	work(1,n,ok);
	if(::ok)puts("YES");
	else puts("NO");
	return 0;
}