#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int M = 2000000;
  vector<char> s(M, '?');
  vector<string> t(n);
  vector<int> k(n);
  vector<vector<int>> x(n);
  for (int i = 0; i < n; i++){
    cin >> t[i] >> k[i];
    x[i] = vector<int>(k[i]);
    for (int j = 0; j < k[i]; j++){
      cin >> x[i][j];
      x[i][j]--;
    }
  }
  set<int> q;
  for (int i = 0; i < M; i++){
    q.insert(i);
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < k[i]; j++){
      int L = x[i][j];
      int R = x[i][j] + t[i].size();
      auto itr1 = q.lower_bound(L);
      auto itr2 = q.lower_bound(R);
      if (itr1 != itr2){
        auto itr = itr1;
        vector<int> upd;
        while (itr != itr2){
          s[*itr] = t[i][*itr - L];
          upd.push_back(*itr);
          itr++;
        }
        for (int pos : upd){
          q.erase(pos);
        }
      }
    }
  }
  string ans;
  for (int i = 0; i < M; i++){
    ans += s[i];
  }
  while (ans.back() == '?'){
    ans.pop_back();
  }
  int L = ans.size();
  for (int i = 0; i < L; i++){
    if (ans[i] == '?'){
      cout << 'a';
    } else {
      cout << ans[i];
    }
  }
  cout << endl;
}