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
#define M 202020
#define INF 200000000000000000ll
LL F[M][2],a,b; int n;
char ch[M];
inline LL solve(){
	n=read(),a=read(),b=read(),scanf("%s",ch+1),ch[0]=ch[n+1]='0';
	memset(F,0x3f,sizeof(F)),F[0][0]=0;//F[0][1]=b;
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++) for(int k=0;k<2;k++)
			F[i][j]=min(F[i][j],F[i-1][k]+(j!=k)*a+j*b);
		if(ch[i]=='1'||ch[i+1]=='1') F[i][0]=INF;
	}
	return F[n][0]+(LL)n*(LL)a+(LL)(n+1)*b;
}
int main(){
	for(int Cas=read();Cas;--Cas) printf("%lld\n",solve());
	return 0;

}


/*
1
8 2 5
00110010

4
8 2 5
00110010
8 1 1
00110010
9 100000000 100000000
010101010
2 5 1
00


*/