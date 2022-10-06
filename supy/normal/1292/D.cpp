#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 35666666;
int n=5000;//5000!!!
Vi pr[666666];int cnt[666666],prime[666666],len,tot,dep[N],pos[666666],fa[N],sz[N];
int main() {
	rep(i,2,n){
		int tmp=i;
		rep(j,2,i)if(i%j==0){
			while(tmp%j==0)tmp/=j,pr[i].pb(j);
		}
		if(SZ(pr[i])==1)prime[++len]=i;
	}
	int cur=0;
	rep(i,2,n){
		int mx=pr[i].back();
		rep(j,1,mx-1)if(cnt[j]){rep(k,1,cnt[j])cur=fa[cur];}
		int rec=cnt[mx];
		rep(j,0,SZ(pr[i])-1)cnt[pr[i][j]]++;
		per(j,mx,2)rep(k,1,cnt[j]-(j==mx?rec:0))
			dep[++tot]=dep[cur]+1,fa[tot]=cur,cur=tot;
		pos[i]=cur;
	}
	ll res=0;int m;read(m);rep(i,1,m){
	    int x;read(x);sz[pos[x]]++;res+=dep[pos[x]];
	}
	per(i,tot,1)sz[fa[i]]+=sz[i];
	int cen=0;
	per(i,tot,0)if(sz[i]*2>=m){cen=i;break;}
//	printf("qwq %d %d %d %d\n",cen,dep[2],dep[3],dep[4]);
	for(int u=cen;u;u=fa[u])res+=m-2*sz[u];
	cout<<res;
//	cout<<tot<<endl;
	return 0;
}