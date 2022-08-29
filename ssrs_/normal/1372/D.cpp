#include <bits/stdc++.h>
using namespace std;
long long select_half(vector<int> &A){
  //N is even
  int N = A.size();
  vector<vector<long long>> dp(N / 2 + 1, vector<long long>(2, 0));
  for (int i = 0; i < N / 2; i++){
    dp[i + 1][0] = dp[i][0] + A[i * 2];
    dp[i + 1][1] = min(dp[i][0], dp[i][1]) + A[i * 2 + 1];
  }
  return min(dp[N / 2][0], dp[N / 2][1]);
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  long long sum = 0;
  for (int i = 0; i < n; i++){
    sum += a[i];
  }
  vector<int> a1(n - 1), a2(n - 1);
  for (int i = 0; i < n - 1; i++){
    a1[i] = a[i];
    a2[i] = a[i + 1];
  }
  cout << sum - min(select_half(a1), select_half(a2)) << endl;
}