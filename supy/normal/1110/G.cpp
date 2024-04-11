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
const int N = 2055555,mo=2;
int n;Vi e[N];int a[N],cnt[N];
void init(int n){
	rep(i,0,n*4)e[i].clear(),a[i]=0,cnt[i]=0;
}
int calc(int u, int v){return SZ(e[u])+SZ(e[v])-2;}
void dfs(int u, int fa, int d, int dot, bool &res){
	if(u==dot){res=d==0;}
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa){
		dfs(e[u][i],u,d^1,dot,res);
	}
}
bool ck(){
	rep(i,1,n)if(SZ(e[i])>=4)return 1;
	if(n<=2)return 0;
	rep(i,1,n)rep(t,0,SZ(e[i])-1){
		int j=e[i][t];
		if(a[i]&&a[j]&&calc(i,j)>=1)return 1;
	}
	rep(i,1,n)if(a[i])rep(t,0,SZ(e[i])-1)cnt[e[i][t]]++;
	rep(i,1,n)if(cnt[i]>=2)return 1;
	rep(i,1,n)if(a[i])rep(t,0,SZ(e[i])-1)if(calc(i,e[i][t])>=2)return 1;
	rep(i,1,n){
		bool gg=0;
		rep(t,0,SZ(e[i])-1){
			int j=e[i][t];
			//suc --> gg=1
			bool ok=0;
			rep(p,0,SZ(e[i])-1)if(e[i][p]!=j){
				int k=e[i][p];
				ok|=calc(i,k)-1>=2;
				rep(q,0,SZ(e[i])-1)if(e[i][q]!=i&&e[i][q]!=j&&e[i][q]!=k&&a[e[i][q]])ok=1;
				rep(q,0,SZ(e[k])-1)if(e[k][q]!=i&&e[k][q]!=j&&e[k][q]!=k&&a[e[k][q]])ok=1;
			}
			if(!ok)gg=1;
		}
		if(!gg)return 1;
	}
	Vi dot;rep(i,1,n)if(SZ(e[i])>=3)dot.pb(i);
	assert(SZ(dot)<=2);
	if(SZ(dot)==2){
		bool ok=0;dfs(dot[0],0,0,dot[1],ok);
		if(ok)return 1;
	}
	return 0;
}
int main() {
	int T;read(T);
	rep(tt,1,T){
		read(n);init(n+1);
		rep(i,1,n-1){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
		/*if(tt==1104){
			rep(i,1,n)rep(j,0,SZ(e[i])-1)if(i<e[i][j])
				printf("edge %d %d\n",i,e[i][j]);
		}*/
		static char t[N];scanf("%s",t+1);
		per(i,n,1)if(t[i]=='W'){
			e[i].pb(n+1);e[n+1].pb(i);
			e[n+1].pb(n+2);e[n+2].pb(n+1);
			e[n+1].pb(n+3);e[n+3].pb(n+1);
			n+=3;
		}
		//rep(i,1,n)a[i]=t[i]=='W';
		printf("%s\n",ck()?"White":"Draw");
	}
	return 0;
}