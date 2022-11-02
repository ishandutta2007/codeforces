#include <bits/stdc++.h>



#define NN 200011

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int h[NN], sum[NN];



int main() {

	int n,k,i,j;

	cin>>n>>k;

	for(i=1; i<=n; i++){

		scanf("%d", h+i);

		sum[i]=sum[i-1]+h[i];

	}

	int mn=1000000000, ans;

	for(i=k; i<=n; i++){

		if(sum[i]-sum[i-k]<mn) mn=sum[i]-sum[i-k], ans=i-k+1;

	}

	cout<<ans<<endl;

	



	return 0;

}