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
#define M 20020
int n,m;
char s[30][M],t[30][M];
int lens[M],lent[M];
int main(){

	// for(int Cas=read();Cas;--Cas) solve();
	n=read(),m=read();
	for(int i=0;i<n;i++) scanf("%s",s[i]),lens[i]=strlen(s[i]);
	for(int i=0;i<m;i++) scanf("%s",t[i]),lent[i]=strlen(t[i]);
	for(int Cas=read(),x;Cas;--Cas){
		x=read()-1; int a=x%n,b=x%m;
		for(int i=0;i<lens[a];i++) putchar(s[a][i]); 
		for(int i=0;i<lent[b];i++) putchar(t[b][i]);
		puts("");		
	}
	return 0;
}