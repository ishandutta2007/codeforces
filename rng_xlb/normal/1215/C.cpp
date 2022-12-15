#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ----------------------------------- "<<endl
#define LL long long
#define DB double
#define LDB long double
#define uint unsigned int
#define ULL unsigned long long
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
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
	inline LL read(){
		LL nm=0; bool fh=true; char cw=getchar();
		for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
		for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
		return fh?nm:-nm;
	}
} using namespace IO;
#define M 400020
int n,m0,m1,t0[M],t1[M];
char s1[M],s2[M];
int main(){
	n=read();
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	for(int i=1;i<=n;i++) if(s1[i]!=s2[i]){
		if(s1[i]=='a') t0[++m0]=i;
		else t1[++m1]=i;
	}
	if((m0+m1)&1){puts("-1");return 0;}
	printf("%d\n",(m0>>1)+(m1>>1)+(m0&1)+(m1&1));
	while(m0>1) printf("%d %d\n",t0[m0],t0[m0-1]),--m0,--m0;
	while(m1>1) printf("%d %d\n",t1[m1],t1[m1-1]),--m1,--m1;
	if(m0>0) printf("%d %d\n",t0[1],t0[1]),printf("%d %d\n",t0[1],t1[1]);
	return 0;
}


/*


*/