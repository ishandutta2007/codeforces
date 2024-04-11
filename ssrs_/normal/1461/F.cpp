#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  string s;
  cin >> s;
  int id = 0;
  for (int i = 0; i < s.size(); i++){
    if (s[i] == '+'){
      id++;
    }
    if (s[i] == '-'){
      id += 2;
    }
    if (s[i] == '*'){
      id += 4;
    }
  }
  if (id == 1 || id == 2 || id == 4 || id == 3){
    char c;
    if (s.size() == 1){
      c = s[0];
    } else {
      c = '+';
    }
    for (int i = 0; i < n; i++){
      cout << a[i];
      if (i < n - 1){
        cout << c;
      }
    }
    cout << endl;
  } else if (id == 6){
    vector<char> op(n - 1, '*');
    for (int i = 1; i < n; i++){
      if (a[i] == 0){
        op[i - 1] = '-';
      }
    }
    for (int i = 0; i < n; i++){
      cout << a[i];
      if (i < n - 1){
        cout << op[i];
      }
    }
    cout << endl;
  } else {
    vector<vector<int>> b(1);
    for (int i = 0; i < n; i++){
      if (a[i] == 0){
        b.push_back(vector<int>());
      } else {
        b.back().push_back(a[i]);
      }
    }
    int m = b.size();
    vector<string> t(m);
    for (int i = 0; i < m; i++){
      int sz = b[i].size();
      if (sz == 0){
        continue;
      }
      vector<char> op(sz - 1, '+');
      vector<int> po, num;
      for (int j = 0; j < sz; j++){
        if (b[i][j] >= 2){
          po.push_back(j);
          num.push_back(b[i][j]);
        }
      }
      if (po.size() > 18){
        int l = po.front();
        int r = po.back();
        for (int j = l; j < r; j++){
          op[j] = '*';
        }
      } else if (!po.empty()){
        int m2 = num.size();
        vector<int> one(m2 + 1);
        one[0] = po[0];
        for (int j = 0; j < m2 - 1; j++){
          one[j + 1] = po[j + 1] - po[j] - 1;
        }
        one[m2] = sz - po[m2 - 1] - 1;
        vector<vector<long long>> pr(m2 + 1, vector<long long>(m2 + 1, 1));
        for (int l = 0; l < m2; l++){
          for (int r = l + 1; r <= m2; r++){
            for (int j = l; j < r; j++){
              pr[l][r] *= num[j];
            }
          }
        }
        vector<vector<long long>> dp(m2 + 1, vector<long long>(m2 + 1, 0));
        for (int d = 1; d <= m2; d++){
          for (int l = 0; l <= m2 - d; l++){
            int r = l + d;
            dp[l][r] = pr[l][r];
            for (int k = l + 1; k < r; k++){
              dp[l][r] = max(dp[l][r], dp[l][k] + one[k] + dp[k][r]);
            }
          }
        }
        queue<pair<int, int>> Q;
        Q.push(make_pair(0, m2));
        while (!Q.empty()){
          int l = Q.front().first;
          int r = Q.front().second;
          Q.pop();
          if (dp[l][r] == pr[l][r]){
            for (int j = po[l]; j < po[r - 1]; j++){
              op[j] = '*';
            }
          } else {
            for (int k = l + 1; k < r; k++){
              if (dp[l][r] == dp[l][k] + one[k] + dp[k][r]){
                Q.push(make_pair(l, k));
                Q.push(make_pair(k, r));
                break;
              }
            }
          }
        }
      }
      for (int j = 0; j < sz; j++){
        t[i] += '0' + b[i][j];
        if (j < sz - 1){
          t[i] += op[j];
        }
      }
    }
    string ans = "";
    for (int i = 0; i < m; i++){
      ans += t[i];
      if (i < m - 1){
        if (!ans.empty()){
          if (ans.back() == '+'){
            ans.pop_back();
          }
        }
        ans += "+0+";
      }
    }
    if (ans.front() == '+'){
      ans.erase(ans.begin());
    }
    if (ans.back() == '+'){
      ans.pop_back();
    }
    cout << ans << endl;
  }
}