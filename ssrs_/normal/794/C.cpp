#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  string t;
  cin >> t;
  int n = s.size();
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());
  deque<char> S, T;
  for (int i = 0; i < n; i++){
    if (i % 2 == 0){
      S.push_back(s[i / 2]);
    } else {
      T.push_back(t[i / 2]);
    }
  }
  int p = -1;
  vector<char> ans(n, '?');
  for (int i = 0; i < n; i++){
    if (i % 2 == 0){
      if (T.empty()){
        ans[i] = S.front();
        S.pop_front();
      } else if (T.front() > S.front()){
        ans[i] = S.front();
        S.pop_front();
      } else {
        p = i;
        break;
      }
    } else {
      if (S.empty()){
        ans[i] = T.front();
        T.pop_front();
      } else if (T.front() > S.front()){
        ans[i] = T.front();
        T.pop_front();
      } else {
        p = i;
        break;
      }
    }
  }
  if (p == -1){
    for (int i = 0; i < n; i++){
      cout << ans[i];
    }
    cout << endl;
  } else {
    /*
    for (int i = 0; i < n; i++){
      cout << ans[i];
    }
    cout << endl;
    */
    if (n % 2 != p % 2){
      for (int i = p; i < n; i++){
        if (i % 2 == 0){
          ans[i] = S.front();
          S.pop_front();
        } else {
          ans[i] = T.front();
          T.pop_front();
        }
      }
    } else {
      for (int i = p; i < n; i++){
        if (i % 2 == 1){
          ans[i] = S.front();
          S.pop_front();
        } else {
          ans[i] = T.front();
          T.pop_front();
        }
      }
    }
    for (int i = 0; i < n; i++){
      cout << ans[i];
    }
    cout << endl;
  }
}