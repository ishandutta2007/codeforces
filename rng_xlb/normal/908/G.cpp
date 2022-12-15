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
#define mod 1000000007
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x-=y;(x<0)?(x+=mod):0;}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 800
int n,F[M][2],G[M][2],ans;
char ch[M]; int t[M];
inline int calc(int D){
	memset(F,0,sizeof(F)),memset(G,0,sizeof(G)),F[n+1][1]=1;
	for(int i=n+1;i>1;--i) for(int j=0;j<2;j++) if(G[i][j]>0||F[i][j]>0){
		for(int d=((j==1)?t[i-1]:9);d>=0;--d){
			int nxt=(j==1&&d==t[i-1]); upd(F[i-1][nxt],F[i][j]);
			if(d>=D) upd(G[i-1][nxt],add(mul(10,G[i][j]),F[i][j]));
			else upd(G[i-1][nxt],G[i][j]);
		}
	} return add(G[1][0],G[1][1]);
}
int main(){
	scanf("%s",ch+1),n=strlen(ch+1),reverse(ch+1,ch+n+1);
	for(int i=1;i<=n;i++) t[i]=ch[i]-'0';
	for(int i=1;i<=9;i++) upd(ans,calc(i));
	printf("%d\n",ans);
	return 0;
}