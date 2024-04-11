#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
using namespace std;
namespace IO{
	const int BS=(1<<23)+5; int Top=0;
	char Buffer[BS],OT[BS],*OS=OT,*HD,*TL,SS[20]; const char *fin=OT+BS-1;
	char Getchar(){if(HD==TL){TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);} return (HD==TL)?EOF:*HD++;}
	void flush(){fwrite(OT,1,OS-OT,stdout),OS=OT;}
	void Putchar(char c){*OS++ =c;if(OS==fin)flush();}
	void write(int x){
		if(!x){Putchar('0');return;} if(x<0) x=-x,Putchar('-');
		while(x) SS[++Top]=x%10,x/=10;
		while(Top) Putchar(SS[Top]+'0'),--Top;
	}
	int read(){
		int nm=0,fh=1; char cw=getchar();
		for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
		for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
		return nm*fh;
	}
} using namespace IO;
#define mod 998244353
#define MD 998244352
namespace KTS{
	int n,m;
	inline int add(int x,int y){x+=y;return (x>=mod)?(x-=mod):x;}
	inline int mns(int x,int y){x-=y;return (x<0)?(x+=mod):x;}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline int qpow(int x,int sq){
		int res=1;
		for(;sq;sq>>=1,x=mul(x,x)) if(sq&1) res=mul(res,x);
		return res;
	}
	map<int,int>MP;
	inline int BSGS(int A,int K){
		int B=ceil(sqrt(mod))+1,k; MP.clear();
		for(int i=0,now=1;i<=B;k=now,i++,now=mul(now,A)) MP[mul(now,K)]=i;
		for(int i=1,now=k;i<=B;i++,now=mul(now,k))
			if(MP.count(now)) return i*B-MP[now]; return -1;
	}
	int gcd(int x,int y){return y?gcd(y,x%y):x;}
	void exgcd(int x,int y,int &tx,int &ty){
		if(!y){tx=1,ty=0;return;}
		exgcd(y,x%y,ty,tx),ty-=tx*(x/y);
	}
	inline int kts(){
		int gg=3,k,t1,t2,v,t;
	//	debug(gg)el;
		t=BSGS(gg,n);
		if(t<0) return -1;
	//	assert(qpow(gg,t)==n);
		if(t%gcd(m,mod-1)!=0) return -1;
		t/=gcd(m,mod-1);
		exgcd(m,mod-1,t1,t2);
		v=((LL)t1*(LL)t%(mod-1)+mod-1)%(mod-1);
	//	debug(v)el;
	//	debug(qpow(gg,v));
		return qpow(gg,v);
	}
}
namespace SOLVE{
	int n,m,K;
	inline int upd(int &x,int y){x+=y;(x>=MD)?(x-=MD):0;}
	inline int mul(int x,int y){return (LL)x*(LL)y%MD;}
	struct MAT{
		int p[102][102];
		inline void init(){memset(p,0,sizeof(p));}
		MAT operator *(const MAT&ot)const{
			MAT tmp; tmp.init();
			for(int i=1;i<=K;i++) for(int j=1;j<=K;j++) for(int k=1;k<=K;k++)
				upd(tmp.p[i][j],mul(p[i][k],ot.p[k][j])); return tmp;
		}
	}Ans,Bas;
	int solve(){
		K=read(),Ans.init(),Bas.init();
		for(int i=1;i<=K;i++) Ans.p[i][i]=1,Bas.p[1][i]=read()%MD;
		for(int i=2;i<=K;i++) Bas.p[i][i-1]=1; n=read(),KTS::n=read();
		for(int sq=n-K;sq;sq>>=1,Bas=Bas*Bas) if(sq&1) Ans=Ans*Bas;
		KTS::m=Ans.p[1][1]; return KTS::kts();
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	printf("%d\n",SOLVE::solve());
	return 0; 
}