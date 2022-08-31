#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> cnt(long long x){
  if (x % 2 == 0){
    return make_pair(x / 2, x / 2);
  } else {
    if (__builtin_parity(x - 1) == 1){
      return make_pair(x / 2, x / 2 + 1);
    } else {
      return make_pair(x / 2 + 1, x / 2);
    }
  }
}
long long sum(vector<vector<int>> &s, int x, int y){
  int n = s.size() - 1;
  int m = s[0].size() - 1;
  pair<long long, long long> P = cnt(x / m);
  pair<long long, long long> Q = cnt(y / n);
  long long ans = 0;
  ans += s[n][m] * (P.first * Q.first + P.second * Q.second);
  ans += (n * m - s[n][m]) * (P.first * Q.second + P.second * Q.first);
  if (__builtin_parity(y / n) == 0){
    ans += s[y % n][m] * P.first;
    ans += (y % n * m - s[y % n][m]) * P.second;
  } else {
    ans += s[y % n][m] * P.second;
    ans += (y % n * m - s[y % n][m]) * P.first;
  }
  if (__builtin_parity(x / m) == 0){
    ans += s[n][x % m] * Q.first;
    ans += (x % m * n - s[n][x % m]) * Q.second;
  } else {
    ans += s[n][x % m] * Q.second;
    ans += (x % m * n - s[n][x % m]) * Q.first;
  }
  if (__builtin_parity(x / m) == __builtin_parity(y / n)){
    ans += s[y % n][x % m];
  } else {
    ans += (y % n) * (x % m) - s[y % n][x % m];
  }
  return ans;
}
int main(){
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> c(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      char ch;
      cin >> ch;
      c[i][j] = ch - '0';
    }
  }
  vector<vector<int>> s(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      s[i + 1][j + 1] += c[i][j];
    }
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      s[i][j] += s[i][j - 1];
    }
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      s[i][j] += s[i - 1][j];
    }
  }
  for (int i = 0; i < q; i++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    cout << sum(s, y2, x2) - sum(s, y2, x1) - sum(s, y1, x2) + sum(s, y1, x1) << endl;
  }
}