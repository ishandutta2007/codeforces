#include <bits/stdc++.h>



#define MOD 1000000007

using namespace std;

typedef long long INT;



#define NN 111111

#define MOD 1000000007

template<typename T, typename U> inline void smin(T &a, U b) {if (a>b) a=b;}

template<typename T, typename U> inline void smax(T &a, U b) {if (a<b) a=b;}



INT sum[1111][21111];



int main() {

	int n,i,j;

	cin>>n;

	INT ans=0;

	for(i=1; i<=n; i++){

		int u;

		scanf("%d", &u);

		ans=(ans+sum[i-1][10000-u]+sum[i-1][10000+u])%MOD;

		for(j=0; j<=20000; j++){

			if(j+u<=20000) sum[i][j+u]=(sum[i][j+u]+sum[i-1][j])%MOD;

			if(j-u>=0) sum[i][j-u]=(sum[i][j-u]+sum[i-1][j])%MOD;

		}

		sum[i][10000+u]++;

		sum[i][10000-u]++;

	}

	cout<<ans<<endl;	

	

	

	return 0;

}