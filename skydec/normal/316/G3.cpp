#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
const int MAXN=1210000;
int go[MAXN][27],right[MAXN][11],len[MAXN],fa[MAXN],tot,last;
char a[MAXN];int t;vector<int>p[MAXN];LL res=0;int L[MAXN],R[MAXN];
inline void add(int x,int ty){
	int p=last;int np=++tot;len[np]=len[p]+1;
	if(ty!=-1)right[np][ty]=1;
	for(;p&&!go[p][x];p=fa[p])go[p][x]=np;
	if(!p)fa[np]=1;
	else{
		int q=go[p][x];
		if(len[q]==len[p]+1)fa[np]=q;
		else{
			int nq=++tot;
			fa[nq]=fa[q];
			len[nq]=len[p]+1;
			rep(i,0,26)go[nq][i]=go[q][i];
			fa[np]=fa[q]=nq;
			for(;p&&go[p][x]==q;p=fa[p])go[p][x]=nq;
		}
	}
	last=np;
}
void dfs(int x){
	rep(i,0,p[x].size()-1){
		dfs(p[x][i]);
		rep(j,0,t)right[x][j]+=right[p[x][i]][j];
	}
	bool can=1;
	rep(j,1,t)if(right[x][j]<L[j]||right[x][j]>R[j])can=0;
	if(!right[x][0])can=0;
	if(can)res+=1ll*(len[x]-len[fa[x]]);
}
int main(){
	scanf("%s",a+1);int n=strlen(a+1);
	last=tot=1;rep(i,1,n)add(a[i]-'a',0);
	scanf("%d",&t);
	rep(i,1,t){
		scanf("%s",a+1);n=strlen(a+1);scanf("%d%d",&L[i],&R[i]);
		add(26,-1);
		rep(j,1,n)add(a[j]-'a',i);
	}
	add(26,-1);
	rep(i,2,tot)p[fa[i]].pb(i);
	dfs(1);
	printf("%I64d\n",res);
	return 0;
}