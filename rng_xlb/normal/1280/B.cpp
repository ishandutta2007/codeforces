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
#define M 200
#define mod 1000000007
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x-=y;(x<0)?(x+=mod):0;}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
int n,m,p[M][M];
char ch[M][M];
inline int S(int sx,int sy,int ex,int ey){--sx,--sy;return p[ex][ey]-p[sx][ey]-p[ex][sy]+p[sx][sy];}
inline void solve(){
	n=read(),m=read(); int ok=0;
	for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		ok+=(p[i][j]=(ch[i][j]=='A'));
		p[i][j]+=p[i-1][j]+p[i][j-1]-p[i-1][j-1];
	} if(!ok){puts("MORTAL");return;} if(ok==n*m){puts("0");return;}
	if(S(1,1,1,m)==m){puts("1");return;}
	if(S(1,1,n,1)==n){puts("1");return;}
	if(S(n,1,n,m)==m){puts("1");return;}
	if(S(1,m,n,m)==n){puts("1");return;}
	if(p[1][1]|S(1,m,1,m)|S(n,1,n,1)|S(n,m,n,m)){puts("2");return;}
	for(int i=1;i<=n;i++) if(S(i,1,i,m)==m){puts("2");return;}
	for(int i=1;i<=m;i++) if(S(1,i,n,i)==n){puts("2");return;}
	if(S(1,1,1,m)){puts("3");return;}
	if(S(1,1,n,1)){puts("3");return;}
	if(S(n,1,n,m)){puts("3");return;}
	if(S(1,m,n,m)){puts("3");return;}
	puts("4"); return;
}
int main(){
	for(int Cas=read();Cas;--Cas) solve();
	return 0;
}