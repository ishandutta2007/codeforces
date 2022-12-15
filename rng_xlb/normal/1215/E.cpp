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
#define maxn 1048576
int n,m,p[20][M],sz[M],lg[1080000];
LL ans,w[20][20],F[1080000],G[20][1080000];
inline bool cmp(int x,int y){return w[x][y]<w[y][x];}
inline void upd(LL &x,LL y){(x>y)?(x=y):0;}
int main(){
	n=read(),memset(F,0x3f,sizeof(F)),F[0]=0;
	for(int i=1,k;i<=n;i++) k=read()-1,p[k][++sz[k]]=i;
	for(int i=0;i<20;i++) for(int j=0;j<20;j++) if(i!=j){
		int rs=0,t1=1,t2=1;
		while(t1<=sz[i]){
			if(t2>sz[j]||p[i][t1]<p[j][t2]) w[i][j]+=rs,t1++;
			else t2++,rs++;
		}
	}
	for(int i=0;i<20;i++) lg[1<<i]=i;
	for(int i=0;i<20;i++) for(int sta=1;sta<maxn;++sta)
		G[i][sta]=w[lg[sta&-sta]][i]+G[i][sta^(sta&-sta)];
	for(int sta=0;sta<maxn;sta++)
		for(int i=0;i<20;i++) if(!((sta>>i)&1))
			upd(F[sta^(1<<i)],F[sta]+G[i][sta]);
	printf("%lld\n",F[maxn-1]);
	return 0;
}


/*


*/