#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=205;
const int jsb=1000000007;
int go[N][22],fail[N],val[N],tot;
int n,m,k;
int l[N],r[N],a[N],q[N];
int up[N];
int f[2][N][505][2];
int g[2][N][505][2];
inline void add(int &x,int y){
	x+=y;if(x>=jsb)x-=jsb;
}
inline int went(int x,int y){
	while(x!=1&&!go[x][y])x=fail[x];
	if(go[x][y])x=go[x][y];
	return x;
}
int work(){
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	g[0][1][0][1]=1;int now=0;
	per(i,203,1){
		rep(pos,1,tot)rep(u,0,k){
			if(up[i]==0)add(g[now^1][pos][u][1],g[now][pos][u][1]);
			else add(f[now^1][pos][u][1],g[now][pos][u][1]);
			add(f[now^1][pos][u][1],f[now][pos][u][1]);
			//g-->g
			add(g[now^1][went(pos,up[i])][min(u+val[went(pos,up[i])],k+1)][0],g[now][pos][u][0]);
			if(up[i]!=0)add(g[now^1][went(pos,up[i])][min(u+val[went(pos,up[i])],k+1)][0],g[now][pos][u][1]);
			
			//f-->f
			rep(j,0,m-1){
				add(f[now^1][went(pos,j)][min(u+val[went(pos,j)],k+1)][0],f[now][pos][u][0]);
				if(j)add(f[now^1][went(pos,j)][min(u+val[went(pos,j)],k+1)][0],f[now][pos][u][1]);
			}
			
			//g-->f
			rep(j,0,up[i]-1){
				add(f[now^1][went(pos,j)][min(u+val[went(pos,j)],k+1)][0],g[now][pos][u][0]);
				if(j)add(f[now^1][went(pos,j)][min(u+val[went(pos,j)],k+1)][0],g[now][pos][u][1]);
			}
		}
		memset(f[now],0,sizeof f[now]);
		memset(g[now],0,sizeof g[now]);
		now^=1;
		/*rep(pos,1,tot)rep(u,0,k)rep(flag,0,1){
			printf("for pos is %d,val is %d,flag is %d :   f=%d   g=%d\n",f[now][pos][u][flag],g[now][pos][u][flag]);
		}*/	
	}
	int ans=0;
	rep(i,1,tot)rep(u,0,k){add(ans,f[now][i][u][0]);add(ans,g[now][i][u][0]);}
	return ans;
}			
int main(){
	scanf("%d%d%d",&n,&m,&k);tot=1;
	scanf("%d",&l[0]);rep(i,1,l[0])scanf("%d",&l[l[0]-i+1]);
	scanf("%d",&r[0]);rep(i,1,r[0])scanf("%d",&r[r[0]-i+1]);
	l[1]--;
	rep(i,1,l[0])if(l[i]<0){
		l[i]+=m;l[i+1]--;
	}
	rep(i,1,n){
		int len;scanf("%d",&len);int now=1;
		rep(j,1,len){
			int dir;scanf("%d",&dir);
			if(!go[now][dir])go[now][dir]=++tot;
			now=go[now][dir];
		}
		int v;scanf("%d",&v);val[now]+=v;
	}
	q[q[0]=1]=1;fail[1]=1;
	rep(i,1,q[0]){
		int x=q[i];
		rep(j,0,m-1)if(go[x][j]){
			int y=go[x][j];
			int p=fail[x];
			while(p!=1&&!go[p][j])p=fail[p];
			if(go[p][j]&&go[p][j]!=y)fail[y]=go[p][j];
			else fail[y]=1;
			q[++q[0]]=y;
		}
	}
	rep(i,1,q[0]){
		int x=q[i];
		val[x]+=val[fail[x]];
	}
	int ans=0;
	rep(i,1,l[0])up[i]=l[i];
	ans=(ans-work())%jsb;
	memset(up,0,sizeof up);
	rep(i,1,r[0])up[i]=r[i];
	ans=(ans+work())%jsb;
	printf("%d\n",(ans+jsb)%jsb);
	return 0;
}