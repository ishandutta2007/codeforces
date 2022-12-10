#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
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

const int N=1000000+3;
const int p=1e9+7;

int P[N],pri[N],vis[N],mu[N],mxp[N],fac[N],A[N],B[N],F[N],G[N];
int n,ans,cnt;

bool is1(int x){
	return x==1||x>n/2&&!vis[x];
}
int cal(int x){
	int w=1;
	while (x>1){
		int t=mxp[x];
		while (x%t==0) x/=t;
		w*=t;
	}
	return w;
}
int sml(int x){
	int w=1;
	while (x>1){
		int t=mxp[x];
		while (x%t==0) x/=t;
		if (1ll*t*t<=n) w*=t;
	}
	return w;
}
void Init(){
	mu[1]=1;
	For(i,2,n+1){
		if (!vis[i]){
			pri[++*pri]=i;
			mu[i]=-1;
			mxp[i]=i;
		}
		for (int j=1;j<=*pri&&pri[j]*i<=n;j++){
			vis[pri[j]*i]=1;
			mxp[pri[j]*i]=mxp[i];
			if (i%pri[j]==0){
				mu[pri[j]*i]=0;
				break;
			} else{
				mu[pri[j]*i]=-mu[i];
			}
		}
	}
}

int main(){
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	n=IN();
	For(i,1,n+1) P[i]=IN();
	Init();
	For(i,n/2+1,n+1) if (!vis[i]) cnt++;
	ans=1;
	For(i,2,n+1) A[cal(i)]++;
	For(i,1,n+1) if (1ll*i*i>n&&2*i<=n&&!vis[i]) B[n/i]++;
	For(i,1,n+1) if (P[i]){
		if (P[i]>1) A[cal(P[i])]--;
		if (is1(i)||is1(P[i])){
			if (!is1(i)||!is1(P[i])) return puts("0"),0;
			cnt--;
		} else{
			if (sml(i)!=sml(P[i])) return puts("0"),0;
			int x=mxp[i],y=mxp[P[i]];
			if (n/x!=n/y) return puts("0"),0;
			if (1ll*x*x>n&&2*x<=n){
//				assert(1ll*y*y>n&&2*y<=n);
				if (F[x]&&F[x]!=y) return puts("0"),0;
				if (G[y]&&G[y]!=x) return puts("0"),0;				
				if (!F[x]){
					F[x]=y;
					G[y]=x;
					B[n/x]--;
				}
			}
		}
	}
	For(i,1,n+1){
		ans=1ll*ans*fac[A[i]]%p;
		ans=1ll*ans*fac[B[i]]%p;
	}
	ans=1ll*ans*fac[cnt+1]%p;
	printf("%d\n",ans);
}