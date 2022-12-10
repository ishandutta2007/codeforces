#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=2000+19;
const int p=998244353;

int f[N][N];
int V[N],P[N],Q[N],A[N],B[N],fac[N],vis[N],d[N],fa[N];
int n,emp,cir,num,a,b,ab,o;

int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void bfs(){
	static int Q[N],vis[N];
	int f=0,w=0;
	For(i,1,n+1){
		if (!d[i]) Q[++f]=i,vis[i]=1;
		fa[i]=i;
	}
	while (f>w){
		int x=Q[++w],y=V[x];
		if (!y){
			num++;
			if (B[getf(x)]){
				if (A[x]) ab++;else b++;
			} else{
				if (A[x]) a++;else o++;
			}
			continue;
		}
		fa[y]=x;Q[++f]=y,vis[y]=1;
	}
	For(i,1,n+1)
		if (!vis[i]){
			cir++;vis[i]=1;
			for (int j=V[i];j!=i;j=V[j]) vis[j]=1;
		}
}

void U(int &x,ll y){
	x=(x+y)%p;
}
void dp(){
	f[0][cir]=1;
	For(i,0,o+a) For(j,0,n+1){
		U(f[i+1][j+1],f[i][j]);
		U(f[i+1][j],1ll*f[i][j]*i);
	}
	For(i,o+a,o+a+b) For(j,0,n+1){
		U(f[i+1][j+1],f[i][j]);
		U(f[i+1][j],1ll*f[i][j]*(i-a));
	}
	For(i,o+a+b,o+a+b+ab) For(j,0,n+1){
		U(f[i+1][j],1ll*f[i][j]*max(i-a-b-2*(i-o-a-b),0));
	}
}

int main(){
	//freopen("perm.in","r",stdin);
	//freopen("perm.out","w",stdout);
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	n=IN();
	For(i,1,n+1) P[i]=IN();
	For(i,1,n+1) Q[i]=IN();
	For(i,1,n+1){
		if (P[i]&&Q[i]){
			V[P[i]]=Q[i];
			d[Q[i]]++;
		}
		if (P[i]&&!Q[i]) A[P[i]]=1;
		if (!P[i]&&Q[i]) B[Q[i]]=1;
		if (!P[i]&&!Q[i]) emp++;
	}
	bfs();
	dp();
	For(i,0,n){
		printf("%d ",1ll*f[num][n-i]*fac[emp]%p);
	}
}