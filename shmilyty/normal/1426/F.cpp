#include <bits/stdc++.h>
using namespace std;
const int M =1e9+7 ;
signed main() {
	int n ;cin >> n;
	string s ;cin >>s ;
	array<int,4>dp={1,0,0,0} ;
	for(char c:s){
		if(c=='?')
			for(int i=3;~i;--i)
				dp[i]=(dp[i]*3LL%M+(!i?0:dp[i-1]))%M ;
		else
			dp[c-'a'+1]= (dp[c-'a'+1]+dp[c-'a'])%M ; 
	}
	cout << dp[3] ;
}