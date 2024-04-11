#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<" ---------------------------------------------- "<<endl
#define uint unsigned int 
#define ULL unsigned long long
#define LDB long double
#define DB double
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
inline LL read(){
	LL nm=0; bool fh=true; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define M 1202000
char ch[M];
int n,m,f[M],hv[M],t[M][2],sz[M],ans=0;
inline int fd(int x){return x==f[x]?x:f[x]=fd(f[x]);}
inline int ot(int x){return (x>m)?(x-m):(x+m);}
inline void merge(int a,int b){
	a=fd(a),b=fd(b); if(a==b) return ;
	int ota=fd(ot(a)),otb=fd(ot(b));
	ans-=min(hv[a],hv[ota]);
	ans-=min(hv[b],hv[otb]);
	f[a]=b,hv[b]+=hv[a],hv[b]=min(hv[b],M+M);
	f[ota]=otb,hv[otb]+=hv[ota],hv[otb]=min(hv[otb],M+M);
	ans+=min(hv[b],hv[otb]);
}
inline void calc(int x){
	if(!sz[x]) return;
	int a0=fd(t[x][0]),a1=fd(t[x][0]+m);
	int b0=fd(t[x][1]),b1=fd(t[x][1]+m);
	if(ch[x]=='1') swap(b0,b1); merge(a0,b1);
}
inline void solve(){
	n=read(),m=read()+n,scanf("%s",ch+1);
	for(int i=1;i<=m+m;i++) f[i]=i,hv[i]=(i>m);
	for(int i=1;i<=n;i++) hv[m+m-n+i]=M+M;
	for(int i=1;i<=n;i++) t[i][0]=t[i][1]=m-n+i;
	for(int i=1;i<=m-n;i++) for(int tt=read(),x;tt;tt--) x=read(),t[x][sz[x]++]=i;
	for(int i=1;i<=n;i++) calc(i),printf("%d\n",ans);
}
int main(){
	for(int Cas=1;Cas;--Cas) solve();
	return 0;
}