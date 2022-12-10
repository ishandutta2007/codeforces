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

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=300000+19;
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

Vi V[N];
int fac[N],inv[N],pre[N],suf[N],id[N],pri[N],vis[N];
int n,x,v,num,res;

void Init(){
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for (int i=N-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	For(i,2,N){
		if (!vis[i]){
			pri[++num]=i;
			id[i]=num;
		}
		for (int j=1;j<=num&&pri[j]*i<N;j++){
			vis[pri[j]*i]=1;
			if (i%pri[j]==0) break;
		}
	}
}
int C(int n,int m){
	return 1ll*fac[n]*inv[m]%p*inv[n-m]%p;
}
void Work(int x){
	int k=n-int(V[x].size());
	sort(V[x].begin(),V[x].end());
	For(i,0,V[x].size()){
		int tmp=0;
		if (k-1>=0) tmp=(tmp+pre[k-1])%p;
		if (k+1<n) tmp=(tmp-suf[k+1]+p)%p;
		res=(res+1ll*V[x][i]*tmp)%p;
		k++;
	}
}

int main(){
	//freopen("set.in","r",stdin);
	//freopen("set.out","w",stdout);
	Init();
	n=IN();
	For(i,0,n) pre[i]=suf[i]=C(n-1,i);
	for (int i=1;i<=n-1;i++) pre[i]=(pre[i]+pre[i-1])%p;
	for (int i=n-2;i>=0;i--) suf[i]=(suf[i]+suf[i+1])%p;
	For(i,1,n+1){
		v=IN();
		for (int x=2;x*x<=v;x++)
			if (v%x==0){
				int c=0;
				while (v%x==0) v/=x,c++;
				V[id[x]].pb(c);
			}
		if (v>1){
			V[id[v]].pb(1);
		}
	}
	For(i,1,num+1) Work(i);
	printf("%d\n",res);
}