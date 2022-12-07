#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n,k;
long long m,f[111][11111],C[111][111],x;

long long pv(long long a,long long b){
	if (!b)return 1;
	long long r=pv(a,b/2);
	r=r*r%M;
	if (b%2)r=r*a%M;
	return r;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);	
	cin >> n >> m >> k;
	C[0][0]=1;
	for (int i=1;i<=n;i++)for (int j=0;j<=i;j++)if (!j)C[i][j]=C[i-1][j];else C[i][j]=(C[i-1][j]+C[i-1][j-1])%M;
	f[0][0]=1;
	for (int i=0;i<n;i++)for (int l=0;l<=n;l++){
		x=pv(C[n][l],m/n+(m%n>i));
		for (int j=0;j+l<=k;j++)if (f[i][j])f[i+1][j+l]=(f[i+1][j+l]+f[i][j]*x)%M;
	}
	CC(f[n][k]);
	return 0;
}