#include <vector>
#include <iostream>
using namespace std;
int main() {
	int q;
	cin >> q;
	while(q--) {
		int N, K;
		cin >> N >> K;
		if(K % 3 != 0) {
			cout << (N % 3 != 0 ? "Alice" : "Bob") << endl;
		}
		else {
			if(N % (K + 1) == K) cout << "Alice" << endl;
			else cout << ((N % (K + 1)) % 3 != 0 ? "Alice" : "Bob") << endl;
		}
	}
	/*
	for(int i = 3; i <= 50; ++i) {
		if(i % 3 != 0) continue;
		vector<bool> dp(51);
		for(int j = 1; j <= 100; ++j) {
			if(!dp[j - 1]) dp[j] = true;
			if(j >= 2 && !dp[j - 2]) dp[j] = true;
			if(j >= i && !dp[j - i]) dp[j] = true;
		}
		cout << (i < 10 ? " " : "") << i << ": ";
		for(int j = 0; j <= 50; ++j) {
			cout << dp[j];
		}
		cout << endl;
	}
	*/
	return 0;
}