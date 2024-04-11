#include <bits/stdc++.h>
using namespace std;
int INF = 100000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int ans = -INF;
  for (int i = -30; i <= 30; i++){
    //Range max = i
    vector<vector<int>> C(1);
    for (int j = 0; j < n; j++){
      if (a[j] <= i){
        C.back().push_back(a[j]);
      } else {
        C.push_back(vector<int>(0));
      }
    }
    int c = C.size();
    for (int j = 0; j < c; j++){
      int L = C[j].size();
      vector<int> S(L + 1, 0);
      for (int k = 0; k < L; k++){
        S[k + 1] = S[k] + C[j][k];
      }
      vector<int> minsum(L, 0);
      for (int k = 1; k < L; k++){
        minsum[k] = min(minsum[k - 1], S[k]);
      }
      int max_rs = -INF;
      for (int k = 0; k < L; k++){
        max_rs = max(max_rs, S[k + 1] - minsum[k]);
      }
      ans = max(ans, max_rs - i);
    }
  }
  cout << ans << endl;
}