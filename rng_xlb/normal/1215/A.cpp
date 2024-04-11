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
int n,m;

int main(){
	int a1=read(),a2=read(),k1=read(),k2=read(),tot=read(),minn=0,maxn=0;
	if(k1<k2) swap(a1,a2),swap(k1,k2);
	minn=max(0,tot-(a1*(k1-1)+a2*(k2-1)));
	assert(k2<=k1);
	maxn=min(a2,tot/k2)+(tot-(min(a2,tot/k2)*k2))/k1;
	printf("%d %d\n",minn,maxn);
	return 0;
}


/*


*/