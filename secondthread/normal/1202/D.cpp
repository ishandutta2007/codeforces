#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
	int T; cin>>T;
	while (T--) {
		int nWays; cin>>nWays;
		int originalQuery=nWays;
		int nEs=1;
		while (nWays>=nEs) {
			nWays-=nEs;
			nEs++;
		}
		vector<int> printed;
		cout<<1<<3<<3;
		printed.push_back(1);
		printed.push_back(3);
		printed.push_back(3);
		nEs--;
		nEs--;
		while (nWays--) {
			printed.push_back(7);
			cout<<7;
		}
		while (nEs--) {
			printed.push_back(3);
			cout<<3;
		}
		printed.push_back(7);
		cout<<7<<'\n';

		assert(printed.size()<=100000);

		int dp[4][printed.size()];
		vector<int> leet;
		leet.push_back(1);
		leet.push_back(3);
		leet.push_back(3);
		leet.push_back(7);
		dp[3][printed.size()-1]=printed[printed.size()-1]==7;
		for (int i=printed.size()-2; i>=0; i--) {
			dp[3][i]=dp[3][i+1]+(printed[i]==7);
		}
		for (int c=2; c>=0; c--) {
			dp[c][printed.size()-1]=0;
			for (int i=printed.size()-2; i>=0; i--) {
				dp[c][i]=dp[c][i+1]+(printed[i]==leet[c]?dp[c+1][i+1]:0);
			}
		}
		assert(dp[0][0]==originalQuery);

	}

	return 0;
}