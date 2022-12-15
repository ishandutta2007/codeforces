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
#define M 2002000
#define mod 1000000007
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x-=y;(x<0)?(x+=mod):0;}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
int n,m,p[M];
char ch[M];
inline int solve(){
	m=read(),scanf("%s",ch+1),n=strlen(ch+1); int ans=n,mx=n;
	for(int i=1;i<=n;i++) p[i]=ch[i]-'0'; int x=0;
	while(x<m){
		++x;
		if(mx<M){
			for(int i=1;i<=(mx-x)*(p[x]-1);++i){
				if(i+mx>=M) break;
				p[i+mx]=p[i+mx-(mx-x)];
			}
		}
		upd(ans,mul(p[x]-1,mns(ans,x)));
		mx=min(mx+(p[x]-1)*(mx-x),M);
	} return ans;
}
int main(){
	for(int Cas=read();Cas;--Cas) printf("%d\n",solve());
	return 0;
}