#include <bits/stdc++.h>
using namespace std;
const int INF = 1100000000;
int lis_length(vector<int> &A){
	int N = A.size();
	vector<int> dp(N, INF);
	for (int i = 0; i < N; i++){
		*upper_bound(dp.begin(), dp.end(), A[i]) = A[i];
	}
	return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 2);
  a[0] = -INF;
  a[n + 1] = INF;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
    a[i] -= i;
  }
  vector<int> b(k + 2);
  b[0] = 0;
  b[k + 1] = n + 1;
  for (int i = 1; i <= k; i++){
    cin >> b[i];
  }
  int ans = 0;
  for (int i = 0; i < k + 1; i++){
    if (a[b[i + 1]] < a[b[i]] ){
      cout << -1 << endl;
      return 0;
    }
    vector<int> s;
    for (int j = b[i] + 1; j < b[i + 1]; j++){
      if (a[j] < a[b[i]] || a[b[i + 1]] < a[j]){
        ans++;
      } else {
        s.push_back(a[j]);
      }
    }
    ans += s.size() - lis_length(s);
  }
  cout << ans << endl;
}