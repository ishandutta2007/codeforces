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
const int MAXN=210000;
const int wei=314000000;
pii a[MAXN];int size;
inline void up(int x){
	while(x!=1&&a[x/2]>a[x]){
		swap(a[x/2],a[x]);
		x/=2;
	}
}
inline void down(int x){
	while(1){
		int rp=x;
		rep(i,0,1)if(x*2+i<=size)if(a[x*2+i]<a[rp])rp=x*2+i;
		swap(a[rp],a[x]);
		if(rp==x)break;x=rp;
	}
}
inline void push(pii c){
	a[++size]=c;up(size);
}
inline pii pop(){
	pii res=a[1];
	a[1]=a[size--];
	down(1);
	return res;
}
int n,m;vector<int>pa[MAXN];int mon[MAXN];vector<int>way[MAXN];int cnt[MAXN];int f[MAXN];
bool dao[MAXN];vector<int>fan[MAXN];int s[MAXN];bool wx[MAXN];int ma[MAXN];int zt[MAXN];
int dfs(int x){
	if(zt[x])return ma[x];
	zt[x]=1;bool wxx=0;
	rep(i,0,way[x].size()-1){
		int y=way[x][i];
		int uccu=-1;
		rep(k,0,pa[y].size()-1)if(f[pa[y][k]]>1e9){uccu=k;break;}
		if(uccu!=-1)continue;
		int val=0;
		rep(k,0,pa[y].size()-1){
			int cao=pa[y][k];
			if(cao==-1)val++;
			else if(zt[cao]==1)wxx=1;
			else{
				val=min(val+dfs(cao),wei);
				if(wx[cao])wxx=1;
			}
		}
		ma[x]=max(ma[x],min(val,wei));
		if(wxx)wx[x]=1;
	}
	zt[x]=2;
	return ma[x];
}
int main(){
	scanf("%d%d",&m,&n);
	rep(i,1,m){
		int k;scanf("%d%d",&mon[i],&k);way[mon[i]].pb(i);
		rep(j,1,k){
			int x;scanf("%d",&x);
			pa[i].pb(x);
			if(x!=-1)fan[x].pb(i),cnt[i]++;
			else s[i]++;
		}
		if(!cnt[i])push(pii(s[i],mon[i]));
	}
	memset(f,60,sizeof f);
	while(size){
		pii haha=pop();
		int w=haha.fi;int x=haha.se;
		if(dao[x])continue;
		dao[x]=1;f[x]=w;
		rep(i,0,fan[x].size()-1){
			int y=fan[x][i];
			s[y]=min(s[y]+w,wei);
			if(--cnt[y]==0)push(pii(s[y],mon[y]));
		}
	}
	rep(i,1,n)if(f[i]<1e9)dfs(i);
	rep(i,1,n)if(f[i]>1e9)printf("-1 -1\n");
	else printf("%d %d\n",f[i],wx[i]?-2:ma[i]);
	return 0;
}