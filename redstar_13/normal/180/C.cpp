#include<bits/stdc++.h>



#define NN 111111

using namespace std;



char s[NN];

int dp[NN];



int main(){

	

	scanf("%s", s+1);

	int n=strlen(s+1);

	for(int i=1; i<=n; i++) if(s[i]<='Z') dp[0]++;

	int ans=dp[0];

		for(int i=1; i<=n; i++) {

		if(s[i]>='a') dp[i]=dp[i-1]+1;

		else dp[i]=dp[i-1]-1;

		ans=min(ans, dp[i]);

	}

	

	cout<<ans<<endl;

	return 0;

}