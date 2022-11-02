#include <bits/stdc++.h>



#define inf 0x3f3f3f3f

#define MOD 1000000007

#define pb push_back

#define sq(x) ((x)*(x))

#define x first

#define y second

#define eps 1e-8

#define bpt(x) (__builtin_popcount(x))

#define bptl(x) (__builtin_popcountll(x))

#define bit(x, y) (((x)>>(y))&1)

#define bclz(x) (__builtin_clz(x))

#define bclzl(x) (__builtin_clzll(x))

#define bctz(x) (__builtin_ctz(x))

#define bctzl(x) (__builtin_ctzll(x))



using namespace std;

typedef long long INT;

typedef vector<int> VI;

typedef pair<int, int> pii;

typedef pair<pii, int> pi3;

typedef double DO;



template<typename T, typename U> inline void smin(T &a, U b) {if (a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, U b) {if (a<b) a=b;}



#define NN 333

int dp[NN+1][NN+1];



int main() {

	int n,i,j,k;

	cin>>n;

	int a[10];

	for(i=0; i<n; i++) scanf("%d", a+i);

	

	

	if(n==1) {

		if(a[0]==0) puts("BitAryo");

		else puts("BitLGM");

		return 0;

	}

	if(n==3) {

		if(a[0]^a[1]^a[2]) puts("BitLGM");

		else puts("BitAryo");

		return 0;

	}

	

	for(i=0; i<NN; i++) dp[i][0]=1, dp[0][i]=1;

	dp[0][0]=0;

	

	for(i=1; i<NN; i++){

		for(j=1; j<NN; j++){

			int ok=0;

			for(k=0; k<i; k++) if(dp[k][j]==0)  ok=1;

			for(k=0; k<j; k++) if(dp[i][k]==0)  ok=1;

			for(k=1; k<=min(i, j); k++) if(dp[i-k][j-k]==0)  ok=1;

			dp[i][j]=ok;

		}

	}

	if(dp[a[0]][a[1]]) puts("BitLGM");

	else puts("BitAryo");

	return 0;

}