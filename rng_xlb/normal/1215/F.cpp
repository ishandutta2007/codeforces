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
#define M 402020
int n,m,fs[M<<4],nt[M<<4],to[M<<4],tmp,cnt,cpl,lim,unq,tot,tim;
int pre[M],suf[M],L[M],R[M],be[M<<2],dfn[M<<2],low[M<<2],S[M<<2],top;
inline void link(int x,int y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
inline void tarjan(int x){
	++tim,dfn[x]=low[x]=tim,S[++top]=x;
	// debug(x)el;
	for(int i=fs[x];i!=-1;i=nt[i]){
		if(!dfn[to[i]]) tarjan(to[i]);
		if(!be[to[i]]) low[x]=min(low[x],low[to[i]]);
	} if(low[x]<dfn[x]) return; ++tot;
	while(!be[x]) be[S[top]]=tot,--top;
}
int main(){
	cpl=read(),n=read(),lim=read(),unq=read(),cnt=n+n;
	//choose = i    not choose = i+n
	memset(fs,-1,sizeof(fs));
	for(int i=1;i<=lim;i++) pre[i]=++cnt,suf[i]=++cnt;
	for(int i=1;i<lim;i++) link(pre[i+1],pre[i]),link(suf[i],suf[i+1]);
	while(cpl--){
		int x=read(),y=read();
		link(x+n,y),link(y+n,x);
	}
	for(int i=1;i<=n;i++){
		L[i]=read(),R[i]=read();
		if(L[i]>1) link(i,pre[L[i]-1]);
		if(R[i]<lim) link(i,suf[R[i]+1]);
		link(pre[R[i]],i+n);
		link(suf[L[i]],i+n);
	}
	while(unq--){
		int x=read(),y=read();
		link(x,y+n),link(y,x+n);
	} 
	for(int i=1;i<=cnt;i++) if(!dfn[i]) tarjan(i); int ans=top=0;
	for(int i=1;i<=n;i++) if(be[i]==be[i+n]){puts("-1");return 0;}
	for(int i=1;i<=n;i++) if(be[i]<be[i+n]) ans=max(ans,L[i]),S[++top]=i;
	printf("%d %d\n",top,ans);
	for(int i=1;i<=top;i++) printf("%d%c",S[i],i<top?' ':'\n');
	return 0;
}