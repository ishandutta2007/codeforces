#include <bits/stdc++.h>



#define NN 3333

using namespace std;

typedef long long INT;

typedef pair<int, int> pii;



int a[NN], b[NN], c[NN], dp[2][NN];



int main() {

	int n,i,j;

	cin>>n;

	

	for(i=1; i<=n; i++) scanf("%d", a+i);

	for(i=1; i<=n; i++) scanf("%d", b+i);

	for(i=1; i<=n; i++) scanf("%d", c+i);



	dp[0][1]=dp[1][1]=a[1];

	dp[0][2]=a[2]+b[1], dp[1][2]=a[1]+b[2];

	

	

	for(i=3; i<=n; i++){

		dp[0][i]=a[i]+max(dp[0][i-1]-a[i-1]+b[i-1], dp[1][i-1]-b[i-1]+c[i-1]);

		dp[1][i]=b[i]+max(dp[1][i-1], dp[0][i-1]);

//		cout<<i<<' '<<dp[0][i]<<' '<<dp[1][i]<<endl;

	}

	cout<<max(dp[0][n], dp[1][n])<<endl;

	

	return 0;

}