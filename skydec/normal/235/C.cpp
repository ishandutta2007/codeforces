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
const int MAXN=2010000;
int go[MAXN][26],step[MAXN],fa[MAXN],tot,last,n,m;
char a[MAXN];int vis[MAXN],size[MAXN];
inline void add(int x){
	int p=last;int np=++tot;step[np]=step[p]+1;size[np]=1;
	for(;p&&!go[p][x];p=fa[p])go[p][x]=np;
	if(!p)fa[np]=1;
	else{
		int q=go[p][x];
		if(step[q]==step[p]+1)fa[np]=q;
		else{
			int nq=++tot;
			fa[nq]=fa[q];
			step[nq]=step[p]+1;
			rep(i,0,25)go[nq][i]=go[q][i];
			fa[q]=fa[np]=nq;
			for(;p&&go[p][x]==q;p=fa[p])go[p][x]=nq;
		}
	}
	last=np;
}
int tmp[MAXN],top[MAXN];
int main(){
	scanf("%s",a+1);n=strlen(a+1);
	tot=last=1;rep(i,1,n)add(a[i]-'a');
	rep(i,1,tot)tmp[step[i]]++;
	rep(i,1,tot)tmp[i]+=tmp[i-1];
	rep(i,1,tot)top[tmp[step[i]]--]=i;
	per(i,tot,1){
		int x=top[i];
		size[fa[x]]+=size[x];
	}
	scanf("%d",&m);
	for(int cas=1;cas<=m;cas++){
		scanf("%s",a+1);n=strlen(a+1);
		LL ans=0;
		rep(i,n+1,2*n)a[i]=a[i-n];
		int me=1;int len=0;
		rep(i,1,n*2){
			int x=a[i]-'a';
			while(me&&!go[me][x])me=fa[me];
			if(!me){me=1;continue;}
			len=min(len,step[me]);
			len++;me=go[me][x];
			if(i<n||len<n)continue;
			while(1){
				int e=fa[me];
				if(step[e]<n)break;
				me=e;
			}
			len=min(len,step[me]);
			if(vis[me]!=cas){
				vis[me]=cas;
				ans+=size[me];
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}