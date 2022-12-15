#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
#define uint unsigned int
#define ULL unsigned long long
#define LDB long double 
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
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
	inline int read(){
		int nm=0; bool fh=true; char cw=getchar();
		for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
		for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
		return fh?nm:-nm;
	}
} using namespace IO;
#define M 602020
#define INF 200000000000000000ll
#define _1 first
#define _2 second
#define mod 998244353
namespace  CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(int x,int y){return (LL)x*(LL)y%mod;}
	inline void upd(int &x,int y){x+=y;(x>=mod)?(x-=mod):0;}
	inline void dec(int &x,int y){x=((x<y)?(x-y+mod):(x-y));}
	inline int qpow(int x,int sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
pii p[M]; int n,ans,fac[M];
int main(){
	n=read(),fac[0]=1;
	for(int i=1;i<=n;i++) p[i]._1=read(),p[i]._2=read();
	for(int i=1;i<=n;i++) fac[i]=mul(fac[i-1],i);
	sort(p+1,p+n+1); int res=1,mx=0; ans=fac[n];
	for(int l=1,r=1;l<=n;l=++r){
		while(r<n&&p[r+1]._1==p[l]._1) ++r;
		res=mul(res,fac[r-l+1]);
	} dec(ans,res);
	res=1;
	for(int i=1;i<=n;i++) swap(p[i]._1,p[i]._2);
	sort(p+1,p+n+1); 
	for(int l=1,r=1;l<=n;l=++r){
		while(r<n&&p[r+1]._1==p[l]._1) ++r;
		res=mul(res,fac[r-l+1]);
	} dec(ans,res),res=1; bool ot=true;
	for(int i=1;ot&&i<=n;i++){
		if(mx>p[i]._2) ot=false;
		else mx=p[i]._2;
	}
	if(ot){
		res=1;
		for(int l=1,r=1;l<=n;l=++r){
			while(r<n&&p[r+1]._1==p[l]._1&&p[r+1]._2==p[l]._2) ++r;
			res=mul(res,fac[r-l+1]);
		} upd(ans,res);
	} printf("%d\n",ans);
	return 0;

}