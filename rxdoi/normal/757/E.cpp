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

const int N=2e6+19;
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

int fac[N],inv[N],pri[N],vis[N],Minp[N];
int r,n,res;

int C(int n,int m){
	if (n<m) return 0;
	return 1ll*fac[n]*inv[m]%p*inv[n-m]%p;
}
int F(int r,int c){
	r++;
	if (r==1) return c==0?1:2;
	return (2ll*C(r+c-1,c)-C(r+c-2,r-2)+p)%p;
}
void Init(){
	For(i,2,N){
		if (!vis[i]) pri[++*pri]=i,Minp[i]=i;
		for (int j=1;j<=*pri&&pri[j]*i<N;j++){
			vis[pri[j]*i]=1;
			Minp[pri[j]*i]=pri[j];
			if (i%pri[j]==0) break;
		}
	}
}

int main(){
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for (int i=N-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	Init();
	for (int Qc=IN();Qc--;){
		r=IN(),n=IN();
		res=1;
		while (Minp[n]){
			int t=Minp[n],c=0;
			while (n%t==0) n/=t,c++;
			res=1ll*res*F(r,c)%p;
		}
		printf("%d\n",res);
	}
}