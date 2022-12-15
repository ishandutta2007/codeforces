#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
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
#define mod 998244353
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x-=y;(x<0)?(x+=mod):0;}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 200200
int n,m;
vector<int>t[M];
LL ans;
int mi[M],mx[M],len[M];
pii p[M];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		len[i]=read(),t[i].pb(0),t[i].pb(0); bool hv=false;
		for(int j=1;j<=len[i];++j) t[i].pb(0),t[i][j]=read();
		for(int j=1;j<len[i];++j) if(t[i][j]<t[i][j+1]) hv=true;
		if(hv) continue;
		p[++m]=mp(t[i][1],-1);
		p[++m]=mp(t[i][len[i]],1);
	} ans=(LL)n*(LL)n-(LL)(m>>1)*(LL)(m>>1),sort(p+1,p+m+1);
	int now=0;
	for(int i=1;i<=m;i++){
		if(p[i].second==1) ++now;
		else ans+=now;
	}
	printf("%lld\n",ans);

	return 0;
}