#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Rep(x) for (int i=las[x],y;~i;i=E[i].nxt) if (!vis[y=E[i].y])
#define Rep2(x) for (int i=las[x],y;~i;i=E[i].nxt) if (y=E[i].y)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if
#define Mid ((L+R)>>1)

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1e5+19;
const int p=998244353;
const int oo=(1<<30)-1;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

namespace poly{
	const int g=3;
	const int N=4e5+19;
	
	int pool[10000000],*cur=pool,*P[N];
	int w[2][N],rev[N];
	int c;
	
	void Prepare(int n){
		int w0=Pow(3,(p-1)/n);
		w[0][0]=w[1][0]=1;
		For(i,1,n){
			w[0][i]=w[1][n-i]=1ll*w[0][i-1]*w0%p;
		}
		int m=0;
		while ((1<<m)!=n) m++;
		For(i,1,n) rev[i]=(rev[i>>1]>>1)|(i&1)<<m-1;
	}
	void NTT(int *A,int n,int f){
		For(i,0,n) if (i<rev[i]) swap(A[i],A[rev[i]]);
		for (int i=1;i<n;i<<=1)
			for (int j=0,t=n/(i<<1);j<n;j+=i<<1)
				for (int k=j,l=0;k<j+i;k++,l+=t){
					int x=A[k],y=1ll*w[f][l]*A[k+i]%p;
					A[k]=(x+y>=p?x+y-p:x+y);
					A[k+i]=(x-y+p>=p?x-y:x-y+p);
				}
		if (f){
			int tmp=Pow(n,p-2);
			For(i,0,n) A[i]=1ll*A[i]*tmp%p;
		}
	}
	void Mul(int *A,int *B,int *C,int n,int m){
		for (c=1;c<n||c<m;c<<=1);c<<=1;
		Prepare(c);
		For(i,n,c) A[i]=0;
		For(i,m,c) B[i]=0;
		NTT(A,c,0);NTT(B,c,0);
		For(i,0,c){
			C[i]=1ll*A[i]*B[i]%p;
			A[i]=0;B[i]=0;
		}
		NTT(C,c,1);
	}
	Vi gao(int *T,int L,int R){
		static int F[N],G[N],H[N];
		if (L==R){
			Vi V;
			V.pb(1);
			V.pb(T[L]);
			return V;
		}
		Vi A=gao(T,L,Mid);
		Vi B=gao(T,Mid+1,R);
		For(i,0,A.size()) F[i]=A[i];
		For(i,0,B.size()) G[i]=B[i];
		Mul(F,G,H,A.size(),B.size());
		Vi C;
		For(i,0,R-L+2) C.pb(H[i]);
		return C;
	}
	Vi work(Vi V){
		if (V.empty()) return (Vi){1};
		static int F[N];
		For(i,0,V.size()) F[i]=V[i];
		return gao(F,0,int(V.size())-1);
	}
}

struct Edge{
	int y,nxt;
} E[N*2];
int las[N],vis[N],sz[N],f[N],g[N],sz2[N],fac[N],inv[N];
int n,k,cnt,ans,mn,cen,fcen,tmp,pre;
map<pii,int> SZ;

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void dfs(int x,int fa){
	sz2[x]=1;
	Rep(x) if (y!=fa){
		dfs(y,x);
		sz2[x]+=sz2[y];
		SZ[mp(y,x)]=sz2[y];
		SZ[mp(x,y)]=n-sz2[y];
	}
}
void findcen(int x,int fa,int n){
	sz[x]=1;
	int tmp=0;
	Rep(x) if (y!=fa){
		findcen(y,x,n);
		sz[x]+=sz[y];
		tmp=max(tmp,sz[y]);
	}
	tmp=max(tmp,n-sz[x]);
	if (tmp<mn) mn=tmp,cen=x,fcen=fa;
}
void calc(int x,int fa){
	Vi V;
	Rep(x) if (y!=fa) calc(y,x);
	Rep2(x) if (y!=fa) V.pb(SZ[mp(y,x)]);
	Vi t=poly::work(V);
	For(i,0,t.size()) if (i<=k){
		tmp=(tmp+1ll*fac[k]*inv[k-i]%p*t[i])%p;
	}
}
void solve(int x,int n){
	mn=oo;
	findcen(x,-1,n);
	vis[x=cen]=1;
	if (~fcen) sz[fcen]=n-sz[x];
	pre=0;
	Vi V;
	Rep2(x) V.pb(SZ[mp(y,x)]);
	Vi f=poly::work(V);
	map<int,int> M;
	Rep(x){
		tmp=0;
		calc(y,x);
		ans=(ans+1ll*pre*tmp)%p;
		pre=(pre+tmp)%p;
		int w=SZ[mp(y,x)];
		if (!M.count(w)){
			Vi g=f;
			For(j,1,g.size()){
				g[j]=(g[j]-1ll*w*g[j-1]%p+p)%p;
			}
			int &res=M[w];
			For(j,0,g.size()) if (j<=k){
				res=(res+1ll*fac[k]*inv[k-j]%p*g[j])%p;
			}
		}
		ans=(ans+1ll*tmp*M[w])%p;
	}
	Rep(x) solve(y,sz[y]);
}

int main(){
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for (int i=N-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	memset(las,-1,sizeof(las));
	n=IN(),k=IN();
	For(i,1,n) Link(IN(),IN());
	if (k==1){
		printf("%d\n",1ll*n*(n-1)/2%p);
		return 0;
	}
	dfs(1,-1);
	solve(1,n);
	printf("%d\n",ans);
}