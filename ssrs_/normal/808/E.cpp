#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> C(3);
  for (int i = 0; i < n; i++){
    int w, c;
    cin >> w >> c;
    C[w - 1].push_back(c);
  }
  vector<int> cnt(3);
  vector<vector<long long>> S(3);
  for (int i = 0; i < 3; i++){
    sort(C[i].begin(), C[i].end(), greater<int>());
    cnt[i] = C[i].size();
    S[i] = vector<long long>(cnt[i] + 1);
    S[i][0] = 0;
    for (int j = 0; j < cnt[i]; j++){
      S[i][j + 1] = S[i][j] + C[i][j];
    }
  }
  vector<long long> sum(m + 1, 0);
  for (int i = 0; i < 2; i++){
    if (i <= cnt[0]){
      priority_queue<int> pq;
      for (int j = i + 2; j <= cnt[0]; j += 2){
        pq.push(S[0][j] - S[0][j - 2]);
      }
      for (int j = 0; j < cnt[1]; j++){
        pq.push(C[1][j]); 
      }
      long long s = S[0][i];
      for (int j = i; j <= m; j += 2){
        sum[j] = s;
        if (!pq.empty()){
          s += pq.top();
          pq.pop();
        }
      }
    }
  }
  for (int i = 0; i < m; i++){
    sum[i + 1] = max(sum[i + 1], sum[i]);
  }
  long long ans = 0;
  for (int i = 0; i <= cnt[2]; i++){
    if (m >= i * 3){
      ans = max(ans, S[2][i] + sum[m - i * 3]);
    }
  }
  cout << ans << endl;
}