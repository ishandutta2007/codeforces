#include <bits/stdc++.h>



#define NN 1111

#define mod 1000000007

using namespace std;

typedef long long INT;



int a[NN];

INT fact[NN], re[NN];



INT power(int u, int n){

	if(!n) return 1LL;

	INT ans=power(u, n/2);

	ans=ans*ans%mod;

	if(n&1) ans=ans*u%mod;

	return ans;

}





int main() {

	int n,m,i,j;

	cin>>n>>m;

	

	for(i=1; i<=m; i++){

		scanf("%d", a+i);

	}

	sort(a+1, a+m+1);

	a[m+1]=n+1;

	

	fact[0]=1;

	for(i=0; i<=n; i++){

		if(i) fact[i]=fact[i-1]*i%mod;

		re[i]=power(fact[i], mod-2);

	}

	

	INT ans=fact[n-m]%mod;

	for(i=1; i<=m+1; i++){

		int u=a[i]-a[i-1]-1;

		if(u==0) continue;

		ans=ans*re[u]%mod;

		if(i!=1 && i!=m+1) ans=ans*power(2, u-1)%mod;

	}

	cout<<ans<<endl;

	return 0;

}