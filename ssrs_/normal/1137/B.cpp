#include <bits/stdc++.h>
using namespace std;
vector<int> z_algorithm(string s){
  int N = s.size();
  vector<int> ans(N);
  for (int i = 1, j = 0; i < N; i++){
    if (i + ans[i - j] < j + ans[j]){
      ans[i] = ans[i - j];
    } else {
      int k = max(0, j + ans[j] - i);
      while (i + k < N && s[k] == s[i + k]){
        k++;
      }
      ans[i] = k;
      j = i;
    }
  }
  ans[0] = N;
  return ans;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  string t;
  cin >> t;
  int N = s.size();
  int M = t.size();
  vector<int> A = z_algorithm(t);
  int c = 0;
  for (int i = 1; i < M; i++){
    if (A[i] + i == M){
      c = M - i;
      break;
    }
  }
  vector<int> cs(2, 0);
  for (int i = 0; i < N; i++){
    cs[s[i] - '0']++;
  }
  vector<int> ct1(2, 0);
  for (int i = 0; i < c; i++){
    ct1[t[i] - '0']++;
  }
  vector<int> ct2(2, 0);
  for (int i = c; i < M; i++){
    ct2[t[i] - '0']++;
  }
  int tv = 0, fv = N + 1;
  while (fv - tv > 1){
    int mid = (tv + fv) / 2;
    long long zero = ct1[0] + (long long) ct2[0] * mid;
    long long one= ct1[1] + (long long) ct2[1] * mid;
    if (zero <= cs[0] && one <= cs[1]){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  if (tv == 0){
    cout << s << endl;
  } else {
    string ans;
    ans += t.substr(0, c);
    for (int i = 0; i < tv; i++){
      ans += t.substr(c);
    }
    int zero = ct1[0] + ct2[0] * tv;
    int one = ct1[1] + ct2[1] * tv;
    for (int i = 0; i < cs[0] - zero; i++){
      ans += '0';
    }
    for (int i = 0; i < cs[1] - one; i++){
      ans += '1';
    }
    cout << ans << endl;
  }
}