#include <bits/stdc++.h>



#define NN 100011

#define inf 1000000000000000LL

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int a[NN], arr[NN];

INT sum[NN], tot[NN];



int main() {

	int n,i,j;

	cin>>n;

	INT ans=0;

	for(i=1; i<=n; i++) scanf("%d", a+i), sum[i]=sum[i-1]+a[i];

	for(i=1; i<=n; i++) scanf("%1d", arr+i), ans+=arr[i]*a[i];

	for(i=n; i>=1; i--) {

		tot[i]=tot[i+1];

		if(arr[i]==1) tot[i]+=a[i];

	}

	for(i=1; i<=n; i++){

		if(arr[i]==0) continue;

		ans=max(ans, sum[i-1]+tot[i+1]);

	}

	cout<<ans<<endl;

	

	

	return 0;

}