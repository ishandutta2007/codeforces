#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lf else if

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

const int p=998244353;
const int N=4000+19;
const int K=80;

struct Edge{
	int y,nxt;
};

int C[N][N];
int k,ans;

void upd(int &x,int y){
	x=(x+y)%p;
}

struct Tree{
	Edge E[N*2];
	int las[N],F[N*2][K/2],ans[K/2],tmp[K/2],G[K/2],vis[N*2];
	int n,cnt;
	Tree(){
		memset(las,-1,sizeof(las));
		cnt=0;
	}
	void Link(int x,int y){
		E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
		E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
	}
	void Input(){
		For(i,1,n) Link(IN(),IN());
	}
	void dp(int x,int fa,int w){
		if (vis[w]) return;
		vis[w]=1;
		for (int i=las[x],y;~i;i=E[i].nxt)
			if ((y=E[i].y)!=fa){
				dp(y,x,i);
			}
		memset(tmp,0,sizeof(tmp));
		for (int i=las[x],y;~i;i=E[i].nxt)
			if ((y=E[i].y)!=fa){
				For(j,0,k/2+1) upd(tmp[j+1],F[i][j]);
			}
		F[w][0]=1;
		For(i,1,k/2+1){
			For(j,1,i+1) F[w][i]=(F[w][i]+1ll*tmp[j]*F[w][i-j])%p;
		}
	}
	void gao(){
		For(x,1,n+1){
			for (int i=las[x];~i;i=E[i].nxt){
				dp(E[i].y,x,i);
			}
			memset(tmp,0,sizeof(tmp));
			for (int i=las[x];~i;i=E[i].nxt){
				For(j,0,k/2+1) upd(tmp[j+1],F[i][j]);
			}
			memset(G,0,sizeof(G));
			G[0]=1;
			For(i,1,k/2+1){
				For(j,1,i+1) G[i]=(G[i]+1ll*tmp[j]*G[i-j])%p;
			}
			For(i,0,k/2+1) upd(ans[i],G[i]);
		}
	}
} A,B;

int main(){
	A.n=IN();
	B.n=IN();
	k=IN();
	if (k&1){
		puts("0");
		return 0;
	}
	A.Input();
	B.Input();
	A.gao();
	B.gao();
	For(i,0,K){
		C[i][0]=1;
		For(j,1,i+1) C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	}
	For(w,0,k+1) if (w%2==0){
		ans=(ans+1ll*C[k][w]*A.ans[w/2]%p*B.ans[(k-w)/2])%p;
	}
	printf("%d\n",ans);
}