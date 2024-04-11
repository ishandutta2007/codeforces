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
#define MN 300005
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
int h[MN],b[MN],Log[MN],sta[MN],top,f[MN];
int st[21][MN];
int pos[MN];
int askmax(int l,int r){
	int lg=Log[r-l+1];
//	cerr<<"ask: "<<l<<" "<<r<<" "<<lg<<": "<<max(st[lg][l],st[lg][r-(1<<lg)+1])<<endl;
	return max(st[lg][l],st[lg][r-(1<<lg)+1]);
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i){
		h[i]=read();
//		if(i<=17)cerr<<h[i]<<" ";
	}
//	cerr<<endl;
	for(int i=1;i<=n;++i){
		b[i]=read();
//		if(i<=17)cerr<<b[i]<<" ";
	}
	Log[0]=-1;for(int i=1;i<=n+1;++i)Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n;++i){
		while(h[i]<h[sta[top]]){pos[top]=0;top--;}
		if(!top||askmax(sta[pos[top]-1],sta[pos[top]]-1)+b[sta[pos[top]]]<askmax(sta[top],i-1)+b[i])pos[top+1]=top+1;
		else pos[top+1]=pos[top];
		sta[++top]=i;
		f[i]=askmax(sta[pos[top]-1],sta[pos[top]]-1)+b[sta[pos[top]]];
		st[0][i]=f[i];
		for(int j=1;i-(1<<j)+1>=0;++j)
			st[j][i-(1<<j)+1]=max(st[j-1][i-(1<<j)+1],st[j-1][i-(1<<j)+1+(1<<j-1)]);
	}
	printf("%lld\n",f[n]);
	return 0;
}