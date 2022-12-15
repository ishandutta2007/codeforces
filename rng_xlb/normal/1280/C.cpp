#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define M 400020
#define mod 1000000007
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x-=y;(x<0)?(x+=mod):0;}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
int n,fs[M],nt[M],to[M],len[M],tmp;
int sz[M],mxs[M],rt;
inline void link(int x,int y,int k){
	nt[tmp]=fs[x],fs[x]=tmp,to[tmp]=y,len[tmp++]=k;
}
LL ans1,ans2,dis[M];
inline void DP1(int x,int last){
	sz[x]=1;
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]^last){
		DP1(to[i],x),sz[x]+=sz[to[i]],mxs[x]=max(mxs[x],sz[to[i]]);
		if(sz[to[i]]&1) ans2+=len[i];
	}
	mxs[x]=max(mxs[x],n-sz[x]);
	if(mxs[x]<mxs[rt]) rt=x;
}
inline void DP2(int x,int last){
	ans1+=dis[x],mxs[x]=0;
	for(int i=fs[x];i!=-1;i=nt[i]) if(to[i]^last)
		dis[to[i]]=dis[x]+len[i],DP2(to[i],x);
}
inline void solve(){
	n=read(),ans1=ans2=0,tmp=0;
	n<<=1,memset(fs,-1,sizeof(int)*(n+5));
	for(int x,y,k,i=1;i<n;i++) x=read(),y=read(),k=read(),link(x,y,k),link(y,x,k);
	mxs[0]=n<<2,rt=0,DP1(1,0),dis[rt]=0,DP2(rt,0);
	printf("%lld %lld\n",ans2,ans1);
}
int main(){
	for(int Cas=read();Cas;--Cas) solve();
	return 0;
}