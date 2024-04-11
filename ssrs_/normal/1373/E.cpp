#include <bits/stdc++.h>
using namespace std;
int f(long long x){
  string S = to_string(x);
  int N = S.size();
  int ans = 0;
  for (int i = 0; i < N; i++){
    ans += S[i] - '0';
  }
  return ans;
}
int f_sum(long long x, int k){
  int ans = 0;
  for (long long i = x; i <= x + k; i++){
    ans += f(i);
  }
  return ans;
}
int main(){
  vector<long long> check;
  for (int i = 0; i < 100; i++){
    check.push_back(i);
  }
  for (int i = 0; i < 16; i++){
    for (int j = 0; j < 16 - i; j++){
      for (int k = 1; k < 10; k++){
        for (int l = 0; l < 10; l++){
          for (int m = 0; m < 10; m++){
            string S;
            S += to_string(k);
            for (int t = 0; t < i; t++){
              S += '9';
            }
            S += to_string(l);
            for (int t = 0; t < j; t++){
              S += '9';
            }
            S += to_string(m);
            check.push_back(stoll(S));
          }
        }
      }
    }
  }
  sort(check.begin(), check.end());
  check.erase(unique(check.begin(), check.end()), check.end());
  int cnt = check.size();
  vector<vector<int>> v(cnt, vector<int>(10, 0));
  for (int i = 0; i < cnt; i++){
    for (int j = 0; j < 10; j++){
      v[i][j] = f_sum(check[i], j);
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    int pos = -1;
    for (int j = 0; j < cnt; j++){
      if (v[j][k] == n){
        pos = j;
        break;
      }
    }
    if (pos == -1){
      cout << -1 << endl;
    } else {
      cout << check[pos] << endl;
    }
  }
}