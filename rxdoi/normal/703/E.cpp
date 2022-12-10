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

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

ll IN(){
	int c,f;ll x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1000+19;
const int oo=(1<<30)-1;

int B[50],a[50],b[50],id[N];
int A[N],n,c,m,tmp;
ll val[N],K,x,y;
ll p[50];
int f1[N][15000],g[N][15000];
ll f2[N][15000];

void Work(ll x){
	for (int i=2;1ll*i*i<=x;i++)
		if (x%i==0){
			p[++c]=i;
			while (x%i==0) a[c]++,x/=i;
		}
	if (x>1){
		p[++c]=x;a[c]=1;
	}
}
int New(int x,int y){
	int res=0;
	For(i,1,c+1){
		int v1=x/B[i]%(a[i]+1),v2=y/B[i]%(a[i]+1);
		res+=min(v1+v2,a[i])*B[i];
	}
	return res;
}
void Upd(int i,int j,pair<int,ll> v,int pre){
	if (v<mp(f1[i][j],f2[i][j])){
		f1[i][j]=v.fi;
		f2[i][j]=v.se;
		g[i][j]=pre;
	}
}
void dfs(int i,int j){
	if (i==1) return;
	dfs(i-1,g[i][j]);
	if (j!=g[i][j]) printf("%d ",id[i-1]);
}

int main(){
	n=IN(),K=IN();
	if (K==1){
		ll mn=1ll<<60;
		int id;
		puts("1");
		For(i,1,n+1){
			ll x=IN();
			if (x<mn) mn=x,id=i;
		}
		printf("%d\n",id);
		return 0;
	}
	Work(K);
	B[c+1]=1;
	for (int i=c;i>=0;i--) B[i]=B[i+1]*(a[i+1]+1);
	For(T,1,n+1){
		x=y=IN();
		For(i,1,c+1){
			b[i]=0;
			while (x%p[i]==0) x/=p[i],b[i]++;
		}
		tmp=0;
		For(i,1,c+1) tmp+=min(b[i],a[i])*B[i];
		if (tmp){
			A[++m]=tmp;
			val[m]=y;
			id[m]=T;
		}
	}
	n=m;
	For(i,0,N) For(j,0,B[0]) f1[i][j]=oo;
	f1[1][0]=0;
	For(i,1,n+1){
		For(j,0,B[0])
			if (f1[i][j]!=oo){
				Upd(i+1,j,mp(f1[i][j],f2[i][j]),j);
				Upd(i+1,New(j,A[i]),mp(f1[i][j]+1,f2[i][j]+val[i]),j);
			}
	}
	if (f1[n+1][B[0]-1]!=oo){
		printf("%d\n",f1[n+1][B[0]-1]);
		dfs(n+1,B[0]-1);
		puts("");
	} else{
		puts("-1");
	}
}