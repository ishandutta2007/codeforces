#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[3][1000001];
int main() {
	string line; cin>>line;
	string real;
	int n=line.size();
	if (n<3) {
		cout<<0<<endl;
		return 0;
	}
	for (int i=0; i<n; i++) {
		if (line[i]=='o')
			real.push_back('o');
		else if (i+1<n && line[i+1]=='v')
			real.push_back('w');
	}
	n=real.size();
	dp[1][n]=dp[0][n]=dp[2][n]=0;
	for (int i=n-1; i>=0; i--) {
		if (real[i]=='w')
			dp[2][i]=dp[2][i+1]+1;
		else
			dp[2][i]=dp[2][i+1];
	}
	string wow="wow";
	for (int c=1; c>=0; c--) {
		for (int i=n-1; i>=0; i--) {
			if (real[i]!=wow[c]) dp[c][i]=dp[c][i+1];
			else dp[c][i]=dp[c][i+1]+dp[c+1][i+1];
		}
	}
	cout<<dp[0][0]<<endl;

	return 0;
}