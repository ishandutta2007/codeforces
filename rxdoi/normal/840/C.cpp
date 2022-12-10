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

const int N=300+19;
const int p=1e9+7;

int C[2*N][2*N];
int A[N],val[N],dp[N][N],sum[N],fac[N];
int n,x,y,m,res;

void Upd(int &x,ll y){
	x=(x+y)%p;
}
void Init(){
	n=IN();
	For(i,1,n+1){
		x=IN();y=1;
		for (int u=2;u*u<=x;u++)
			if (x%u==0){
				int c=0;
				while (x%u==0) x/=u,c++;
				if (c&1) y*=u;
			}
		if (x>1) y*=x;
		int b=0;
		For(j,1,m+1) if (val[j]==y){
			A[j]++;
			b=1;
			break; 
		}
		if (!b){
			val[++m]=y;
			A[m]=1;
		}
	}
	sum[0]=1;
	For(i,1,m+1) sum[i]=sum[i-1]+A[i];
}

int main(){
	For(i,0,2*N){
		C[i][0]=1;
		For(j,1,i+1) C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	}
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	Init();
	dp[0][0]=1;
	For(i,0,m){
		For(j,0,N) if (dp[i][j]){
			for (int x=0;x<=j&&x<=A[i+1];x++)
				for (int y=0;y<=sum[i]-j&&x+y<=A[i+1];y++){
					Upd(dp[i+1][j-x+A[i+1]-x-y],1ll*dp[i][j]*C[j][x]%p*C[sum[i]-j][y]%p*C[A[i+1]-1][x+y-1]);
				}
		}
	}
	res=dp[m][0];
	For(i,1,m+1) res=1ll*res*fac[A[i]]%p;
	printf("%d\n",res);
}