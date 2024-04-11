#include <bits/stdc++.h>
using namespace std;
int calc(string &s){
  int n = s.size();
  vector<int> S(n + 1, 0);
  for (int i = 0; i < n; i++){
    if (s[i] == '('){
      S[i + 1] = S[i] + 1;
    }
    if (s[i] == ')'){
      S[i + 1] = S[i] - 1;
    }
  }
  int m = 0;
  for (int i = 0; i <= n; i++){
    m = min(m, S[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (S[i] == m){
      ans++;
    }
  }
  return ans;
}
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n % 2 == 1){
    cout << 0 << endl;
    cout << 1 << ' ' << 1 << endl;
    return 0;
  }
  vector<int> S(n + 1, 0);
  for (int i = 0; i < n; i++){
    if (s[i] == '('){
      S[i + 1] = S[i] + 1;
    }
    if (s[i] == ')'){
      S[i + 1] = S[i] - 1;
    }
  }
  if (S[n] != 0){
    cout << 0 << endl;
    cout << 1 << ' ' << 1 << endl;
    return 0;
  }
  int m = 0;
  for (int i = 0; i <= n; i++){
    m = min(m, S[i]);
  }
  int ans = calc(s);
  int ansl = 0, ansr = 0;
  if (m < 0){
    int L;
    for (int i = 0; i < n; i++){
      if (S[i] == m){
        L = i;
        break;
      }
    }
    int R;
    for (int i = n - 1; i >= 0; i--){
      if (S[i] == m){
        R = i;
        break;
      }
    }
    swap(s[L - 1], s[R]);
    int tmp = calc(s);
    swap(s[L - 1], s[R]);
    if (tmp > ans){
      ans = tmp;
      ansl = L - 1;
      ansr = R;
    }
    if (m < -1){
      int L2;
      for (int i = 0; i < n; i++){
        if (S[i] == m + 1){
          L2 = i;
          break;
        }
      }
      int R2;
      for (int i = n - 1; i >= 0; i--){
        if (S[i] == m + 1){
          R2 = i;
          break;
        }
      }
      swap(s[L2 - 1], s[R2]);
      int tmp = calc(s);
      swap(s[L2 - 1], s[R2]);
      if (tmp > ans){
        ans = tmp;
        ansl = L2 - 1;
        ansr = R2;
      }
    }
  }
  int tmp = calc(s);
  vector<int> pos;
  for (int i = 0; i <= n; i++){
    if (S[i] <= m + 1){
      pos.push_back(i);
    }
  }
  int cnt = pos.size();
  for (int i = 0; i < cnt - 1; i++){
    int L = pos[i];
    int R = pos[i + 1];
    int add = 0;
    for (int j = L; j < R; j++){
      if (S[j] == m + 2){
        add++;
      }
    }
    if (tmp + add > ans){
      ans = tmp + add;
      ansl = L;
      ansr = R - 1;
    }
  }
  vector<int> pos2;
  for (int i = 0; i <= n; i++){
    if (S[i] == m){
      pos2.push_back(i);
    }
  }
  int cnt2 = pos2.size();
  for (int i = 0; i < cnt2 - 1; i++){
    int L = pos2[i];
    int R = pos2[i + 1];
    int add = 0;
    for (int j = L; j < R; j++){
      if (S[j] == m + 1){
        add++;
      }
    }
    if (add > ans){
      ans = add;
      ansl = L;
      ansr = R - 1;
    }
  }
  cout << ans << endl;
  cout << ansl + 1 << ' ' << ansr + 1 << endl;
}