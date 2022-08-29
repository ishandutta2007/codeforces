#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<vector<int>> A(2, vector<int>(n));
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < n; j++){
      cin >> A[i][j];
    }
  }
  vector<vector<int>> B(2, vector<int>(n));
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < n; j++){
      cin >> B[i][j];
    }
  }
  int sumA = 0, sumB = 0;
  //https://www.ioi-jp.org/joi/2018/2019-ho/2019-ho-t4-review.pdf
  long long ans = 0, d1 = 0, d2 = 0;
  for (int i = 0; i < n; i++){
    sumA += A[0][i] + A[1][i];
    sumB += B[0][i] + B[1][i];
    d1 += A[0][i] - B[0][i];
    d2 += A[1][i] - B[1][i];
    if (d1 > 0 && 0 > d2){
      int t = min(d1, -d2);
      ans += t;
      d1 -= t;
      d2 += t;
    }
    if (d1 < 0 && 0 < d2){
      int t = min(-d1, d2);
      ans += t;
      d1 += t;
      d2 -= t;
    }
    ans += abs(d1);
    ans += abs(d2);
  }
  if (sumA != sumB){
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}