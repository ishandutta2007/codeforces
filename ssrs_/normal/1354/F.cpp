#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int N, K;
    cin >> N >> K;
    vector<tuple<int, int, int>> M(N);
    for (int j = 0; j < N; j++){
      int a, b;
      cin >> a >> b;
      M[j] = make_tuple(b, a, j);
    }
    sort(M.begin(), M.end());
    reverse(M.begin(), M.end());
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, -INF));
    vector<vector<int>> prev(N + 1, vector<int>(K + 1, -1));
    dp[0][0] = 0;
    for (int j = 0; j < N; j++){
      for (int k = 0; k <= K; k++){
        if (dp[j][k] != INF){
          dp[j + 1][k] = dp[j][k] + get<0>(M[j]) * (K - 1);
          prev[j + 1][k] = 1;
        }
      }
      for (int k = 0; k < K; k++){
        int tmp = dp[j][k] + get<1>(M[j]) + get<0>(M[j]) * (K - 1 - k);
        if (dp[j + 1][k + 1] < tmp){
          dp[j + 1][k + 1] = tmp;
          prev[j + 1][k + 1] = 2;
        }
      }
    }
    int curr_j = N;
    int curr_k = K;
    vector<int> one;
    vector<int> two;
    vector<int> res(N, -1);
    while (curr_j > 0){
      if (prev[curr_j][curr_k] == 2){
        curr_j--;
        curr_k--;
        two.push_back(get<2>(M[curr_j]) + 1);
      } else {
        curr_j--;
        one.push_back(get<2>(M[curr_j]) + 1);
      }
    }
    int cnt1 = one.size();
    int cnt2 = two.size();
    vector<int> ans;
    for (int j = 0; j < cnt2 - 1; j++){
      ans.push_back(two[j]);
    }
    for (int j = 0; j < cnt1; j++){
      ans.push_back(one[j]);
      ans.push_back(-one[j]);
    }
    ans.push_back(two[cnt2 - 1]);
    int m = ans.size();
    cout << m << endl;
    for (int j = 0; j < m; j++){
      cout << ans[j];
      if (j < m - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}