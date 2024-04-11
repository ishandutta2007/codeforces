#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
string bit(int n){
  string S;
  while (n > 0){
    S += n % 2 + '0';
    n /= 2;
  }
  reverse(S.begin(), S.end());
  return S;
}
int main(){
  int n;
  cin >> n;
  vector<int> ans(n, INF);
  string S = bit(n - 1);
  int m = S.size();
  for (int i = 0; i < m * 2; i++){
    if (i % 2 == 0){
      vector<int> w;
      for (int j = 0; j < n; j++){
        if (j >> (i / 2) & 1){
          w.push_back(j);
        }
      }
      int k = w.size();
      cout << k << endl;
      for (int j = 0; j < k; j++){
        cout << w[j] + 1;
        if (j < k - 1){
          cout << ' ';
        }
      }
      cout << endl;
      for (int j = 0; j < n; j++){
        int res;
        cin >> res;
        if (!(j >> (i / 2) & 1)){
          ans[j] = min(ans[j], res);
        }
      }
    } else {
      vector<int> w;
      for (int j = 0; j < n; j++){
        if (!(j >> (i / 2) & 1)){
          w.push_back(j);
        }
      }
      int k = w.size();
      cout << k << endl;
      for (int j = 0; j < k; j++){
        cout << w[j] + 1;
        if (j < k - 1){
          cout << ' ';
        }
      }
      cout << endl;
      for (int j = 0; j < n; j++){
        int res;
        cin >> res;
        if (j >> (i / 2) & 1){
          ans[j] = min(ans[j], res);
        }
      }
    }
  }
  cout << -1 << endl;
  for (int i = 0; i < n; i++){
    cout << ans[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}