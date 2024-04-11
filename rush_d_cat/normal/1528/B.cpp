#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
const LL mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; 
	cin >> n;
	vector<LL> dp(n + 1, 0), s(n + 1, 0), c(n+1, 0);
	for (int i = 1; i <= n; i ++) for (int j = i; j <= n; j += i) c[j] ++;
	for (int i = 1; i <= n; i ++) {
		dp[i] = (s[i-1] + c[i]) % mod;
		s[i] = (s[i-1] + dp[i]) % mod;
	}	
	cout << dp[n] << endl;
}