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
#define M 55
int p[M][M],t[M][M],X[M*M],Y[M*M],tot,n,m;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		p[i][j]=read();
	for(int i=1;i<n;i++) for(int j=1;j<m;j++){
		if(!(p[i][j]&p[i+1][j]&p[i][j+1]&p[i+1][j+1])) continue;
		t[i][j]=t[i][j+1]=t[i+1][j]=t[i+1][j+1]=1,++tot;
		X[tot]=i,Y[tot]=j;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		if(p[i][j]!=t[i][j]){puts("-1");return 0;}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++) printf("%d %d\n",X[i],Y[i]);
	return 0;
}