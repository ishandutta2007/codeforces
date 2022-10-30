#include<bits/stdc++.h>



#define NN 211111

using namespace std;



int dp[NN], L[NN], R[NN],a[NN], pos[NN];



multiset<int> s[NN];



int main(){

	int n,i,j;

	cin>>n;

	double ans=0;

	for(i=0; i<n; i++){

		int u;

		scanf("%d", &u);

		ans+=(double)u/n;

	}

	printf("%.10lf\n", ans);

	

	

}