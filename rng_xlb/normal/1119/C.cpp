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
	int read(){
		int nm=0,fh=1; char cw=getchar();
		for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
		for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
		return nm*fh;
	}
} using namespace IO;
#define M 520
int n,m,p[M],ans,h,A[M][M],B[M][M],C[M][M];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) A[i][j]=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) B[i][j]=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) C[i][j]=A[i][j]^B[i][j];
	for(int i=1;i<=n;i++){
		int res=0;
		for(int j=1;j<=m;j++) res^=C[i][j];
		if(res){puts("No");return 0;}
	}
	for(int j=1;j<=m;j++){
		int res=0;
		for(int i=1;i<=n;i++) res^=C[i][j];
		if(res){puts("No");return 0;}
	} puts("Yes");
	return 0;
}