#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long modpow(long long a, long long b){
	long long ans = 1;
	while (b > 0){
		if (b % 2 == 1){
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return ans;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    int cnt = 0;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        if (s[j][k] == '#'){
          cnt++;
        }
      }
    }
    long long ans = modpow(2, cnt);
    if (cnt == n * m){
      ans--;
    }
    cout << ans << endl;
  }
}