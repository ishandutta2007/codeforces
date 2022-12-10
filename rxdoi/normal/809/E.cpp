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
#define Rep(x) for (int i=las[x],y;~i;i=E[i].nxt) if (!vis[y=E[i].y])
#define pb push_back
#define mp make_pair
#define fi first
#define se second

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

const int N=200000+19;
const int top=200000;
const int p=1e9+7;
const int oo=(1<<30)-1;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

struct Edge{
	int y,nxt;
} E[N*2];
typedef int one[N];
int stk[10000000];
one las,val,mu,phi,A,B,pri,vis,sz,sum0,sum1;
int n,cnt,cen,mn,fcen,s,res;
Vi V[N];

void Init(){
	mu[1]=1;
	phi[1]=1;
	For(i,2,n+1){
		if (!vis[i]){
			pri[++*pri]=i;
			mu[i]=p-1;
			phi[i]=i-1;
		}
		for (int j=1;j<=*pri&&pri[j]*i<=n;j++){
			vis[pri[j]*i]=1;
			if (i%pri[j]==0){
				mu[pri[j]*i]=0;
				phi[pri[j]*i]=phi[i]*pri[j];
				break;
			} else{
				mu[pri[j]*i]=p-mu[i];
				phi[pri[j]*i]=phi[i]*(pri[j]-1);
			}
		}
	}
	For(i,1,n+1){
		B[i]=1ll*i*Pow(phi[i],p-2)%p;
		for (int j=1;i*j<=n;j++){
			A[i*j]=(A[i*j]+1ll*mu[j]*B[i])%p;
			V[i*j].pb(i);
		}
	}
}
void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
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
void Qry(int n,int dis){
	int tmp=0;
	for (int d:V[n]){
		tmp=(tmp+1ll*A[d]*sum0[d]%p*dis)%p;
		tmp=(tmp+1ll*A[d]*sum1[d])%p;
	}
	res=(res+1ll*tmp*phi[n])%p;
}
void Ins(int n,int dis){
	for (int d:V[n]){
		sum0[d]=(sum0[d]+phi[n])%p;
		sum1[d]=(sum1[d]+1ll*phi[n]*dis)%p;
		stk[++s]=d;
	}
}
void dfs_Qry(int x,int fa,int d){
	Qry(val[x],d);
	Rep(x) if (y!=fa) dfs_Qry(y,x,d+1);
}
void dfs_Ins(int x,int fa,int d){
	Ins(val[x],d);
	Rep(x) if (y!=fa) dfs_Ins(y,x,d+1);
}
void solve(int x,int n){
	mn=oo;
	findcen(x,-1,n);
	vis[x=cen]=1;
	if (~fcen) sz[fcen]=n-sz[x];
	Ins(val[x],0);
	Rep(x){
		dfs_Qry(y,x,1);
		dfs_Ins(y,x,1);
	}
	for (;s;s--){
		sum0[stk[s]]=sum1[stk[s]]=0;
	}
	Rep(x) solve(y,sz[y]);
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();
	For(i,1,n+1) val[i]=IN();
	Init();
	For(i,1,n) Link(IN(),IN());
	memset(vis,0,sizeof(vis));
	solve(1,n);
	res=1ll*res*Pow(1ll*n*(n-1)/2%p,p-2)%p;
	printf("%d\n",res);
}