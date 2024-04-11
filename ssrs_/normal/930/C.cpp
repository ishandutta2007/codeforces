#include <bits/stdc++.h>
using namespace std;
int INF = 10000000;
vector<int> longest_nondecreasing_subsequence_length_2(vector<int> &A){
	int N = A.size();
	vector<int> dp(N, INF);
	vector<int> res(N + 1, 0);
	for (int i = 0; i < N; i++){
		*lower_bound(dp.begin(), dp.end(), A[i] + 1) = A[i];
		res[i + 1] = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
	}
	return res;
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++){
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
  }
  //imos
  vector<int> d(m + 1, 0);
  for (int i = 0; i < n; i++){
    d[l[i]]++;
    d[r[i] + 1]--;
  }
  for (int i = 1; i <= m; i++){
    d[i] += d[i - 1];
  }
  d.pop_back();
  vector<int> L = longest_nondecreasing_subsequence_length_2(d);
  reverse(d.begin(), d.end());
  vector<int> R = longest_nondecreasing_subsequence_length_2(d);
  reverse(R.begin(), R.end());
  /*
  for (int i = 0; i <= m; i++){
    cout << L[i] << ' ';
  }
  cout << endl;
  for (int i = 0; i <= m; i++){
    cout << R[i] << ' ';
  }
  cout << endl;
  */
  int ans = 0;
  for (int i = 0; i <= m; i++){
    ans = max(ans, L[i] + R[i]);
  }
  cout << ans << endl;
}