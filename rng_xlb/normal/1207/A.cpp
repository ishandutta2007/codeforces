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
int main(){
	for(int Cas=read();Cas;--Cas){
		int tot=read(),a=read(),b=read();
		int ca=read(),cb=read(),ans=0;
		if(ca<cb) swap(ca,cb),swap(a,b);
		int ta=min(tot>>1,a);
		ans=ta*ca,tot-=ta+ta;
		ans+=min(tot>>1,b)*cb;
		printf("%d\n",ans);
	}
	return 0;
}


/*


*/