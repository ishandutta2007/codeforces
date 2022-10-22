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
int b[MN];
char ch[MN];
int gcd(int a,int b){if(!b)return a;return gcd(b,a%b);}
queue<pii >q;
int del[MN],nxt[MN];
signed main(){
	T=read();
	while(T--){
		while(!q.empty())q.pop();
		n=read();
		for(int i=1;i<=n;++i)del[i]=0;
		for(int i=1;i<=n;++i)b[i]=read();
		int lst=1;
		for(int i=1;i<=n;++i)nxt[i]=i+1;
		nxt[n]=1;
		for(int i=2;i<=n;++i){
			if(!del[i]&&!del[i-1]&&gcd(b[i],b[i-1])==1){
				q.push(mp(i-1,i));
				del[i]=1;
				lst=i;
			}
		}
		if(!del[1]&&!del[n]&&gcd(b[1],b[n])==1){
			q.push(mp(n,1));
			del[1]=1;
		}
		vector<int>ans(0);
		int TOT=0;
		while(!q.empty()){
			pii w=q.front();q.pop();
			ans.push_back(w.y);
			TOT++;
			if(TOT==n)break;
			while(del[nxt[w.y]])nxt[w.y]=nxt[nxt[w.y]];
			if(del[nxt[w.y]]||del[w.x])continue;
			if(gcd(b[w.x],b[nxt[w.y]])==1){
				q.push(mp(w.x,nxt[w.y]));
				del[nxt[w.y]]=1;
			}
		}
		printf("%lld ",(int)ans.size());
		for(int i=0;i<ans.size();++i)printf("%lld ",ans[i]);
		puts("");
	}
	return 0;
}