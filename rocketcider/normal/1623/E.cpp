#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int inf=0x3f3f3f3f,maxn=2e5+10;
int a[maxn],cnt,dfn[maxn],l[maxn],k,m,n,r[maxn],rev[maxn],t_case;
bool f[maxn],g[maxn];
char s[maxn];
void dfs1(int p){
	if(p){
		dfs1(l[p]);
		dfn[p]=++cnt,rev[cnt]=p;
		dfs1(r[p]);
	}
}
bool dfs2(int p,int dep){
	if(l[p]&&dfs2(l[p],dep+1))f[p]=true;
	if(r[p]){
		if(f[p]||(g[dfn[p]]&&k>=dep)){
			if(!f[p])f[p]=1,k-=dep;
			dfs2(r[p],1);
		}
		else if(dfs2(r[p],inf))f[p]=1;
	}
	else if(!f[p]&&g[dfn[p]]&&k>=dep)f[p]=1,k-=dep;
	return f[p];
}
void print(int p){
	if(p){
		print(l[p]);
		putchar(s[p]);
		if(f[p])putchar(s[p]);
		print(r[p]);
	}
}
int main(){
	scanf("%d%d%s",&n,&k,s+1);
	for(ri i=1;i<=n;++i)scanf("%d%d",l+i,r+i);
	dfs1(1);
	for(ri i=n-1;~i;--i){
		if(s[rev[i]]!=s[rev[i+1]])g[i]=(s[rev[i]]<s[rev[i+1]]);
		else g[i]=g[i+1];
	}
	dfs2(1,1);
	print(1);
	return 0;
}