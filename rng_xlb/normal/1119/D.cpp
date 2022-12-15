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
	LL read(){
		LL nm=0,fh=1; char cw=getchar();
		for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
		for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
		return nm*fh;
	}
} using namespace IO;
#define M 500000
int n; LL p[M],df[M],dt[M],pre[M],ans;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) p[i]=read(); sort(p+1,p+n+1);
	for(int i=1;i<n;i++) dt[i]=p[i+1]-p[i]; sort(dt+1,dt+n);
	for(int i=1;i<n;i++) pre[i]=pre[i-1]+dt[i];
	for(int Cas=read();Cas;--Cas){
		LL l=read(),r=read(),len,cts; len=r-l+1;
		int k=lower_bound(dt+1,dt+n,len)-dt-1;
		ans=len*(LL)(n-k)+pre[k]; printf("%lld ",ans);
	} puts(""); return 0;
}