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
int n,dt,ad,ms;
char ch[M];
inline void fail(){puts("Monocarp");exit(0);}
inline void win(){puts("Bicarp");exit(0);}
int main(){
	n=read();
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++){
		if(i<=(n>>1)){
			if(ch[i]=='?') ad++;
			else dt+=ch[i]-'0';
		}
		else{
			if(ch[i]=='?') ms++;
			else dt-=ch[i]-'0';
		}
	}
	if(dt<0) swap(ad,ms),dt=-dt;
	dt+=ad*9,ms+=ad;
	if(dt-9*(ms>>1)!=0) fail();
	win();
	return 0;
}


/*


*/