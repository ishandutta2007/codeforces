#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[1002][1002];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++) cin >> a[i][j];
		}
		int ans = 0;
		for(int k = 0; k < n / 2; k++){
			if(k % 4 >= 2) continue;
			for(int i = k; i < n - k; i += 2) ans ^= a[i][k] ^ a[i + 1][k] ^ a[i][n - k - 2] ^ a[i + 1][n - k - 2];
			for(int j = k + 2; j < n - k - 2; j += 2) ans ^= a[k][j] ^ a[k + 1][j] ^ a[n - k - 2][j] ^ a[n - k - 1][j];
			if(k == n / 2 - 1) ans ^= a[k][k] ^ a[k + 1][k];
		}
		cout << ans << "\n";
	}
}