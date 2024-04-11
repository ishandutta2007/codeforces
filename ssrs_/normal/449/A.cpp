#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, pair<long long, long long>>> quotient_ranges(long long N){
	vector<pair<long long, pair<long long, long long>>> ans;
	for (long long i = 1; i * i <= N; i++){
		ans.push_back(make_pair(N / i, make_pair(i, i)));
	}
	for (long long i = N / ((long long) sqrt(N) + 1); i >= 1; i--){
		ans.push_back(make_pair(i, make_pair(N / (i + 1) + 1, N / i)));
	}
	return ans;
}
int main(){
  long long n, m, k;
  cin >> n >> m >> k;
  if (k > n + m - 2){
    cout << -1 << endl;
  } else {
    vector<pair<long long, pair<long long, long long>>> Q = quotient_ranges(n);
    int cnt = Q.size();
    long long ans = 0;
    for (int i = 0; i < cnt; i++){
      long long q = Q[i].first;
      int r = Q[i].second.second;
      int k1 = r - 1;
      int k2 = k - k1;
      if (k2 < 0){
        ans = max(ans, q * m);
      } else if (k2 <= m - 1){
        long long q2 = m / (k2 + 1);
        ans = max(ans, q * q2);
      }
    }
    cout << ans << endl;
  }
}