#include <bits/stdc++.h>
using namespace std;
long long inversion_number(vector<int> &A){
  int N = A.size();
  long long ans = 0;
  int zero = 0;
  for (int i = 0; i < N; i++){
    if (A[i] == 1){
      ans += zero;
    } else {
      zero++;
    }
  }
  return ans;
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int x = 0;
  long long ans = 0;
  vector<vector<int>> a2;
  a2.emplace_back(a);
  for (int i = 29; i >= 0; i--){
    long long sum0 = 0;
    long long sum1 = 0;
    int cnt = a2.size();
    vector<vector<int>> a3;
    for (int j = 0; j < cnt; j++){
      int sz = a2[j].size();
      vector<int> tmp0(sz), tmp1(sz);
      vector<int> zero, one;
      for (int k = 0; k < sz; k++){
        if (a2[j][k] >> i & 1){
          tmp0[k] = 1;
          tmp1[k] = 0;
          one.push_back(a2[j][k]);
        } else {
          tmp0[k] = 0;
          tmp1[k] = 1;
          zero.push_back(a2[j][k]);
        }
      }
      if (!zero.empty()){
        a3.emplace_back(zero);
      }
      if (!one.empty()){
        a3.emplace_back(one);
      }
      sum0 += inversion_number(tmp0);
      sum1 += inversion_number(tmp1);
    }
    if (sum1 > sum0){
      x += (1 << i);
    }
    ans += min(sum0, sum1);
    swap(a2, a3);
  }
  cout << ans << ' ' << x << endl;
}