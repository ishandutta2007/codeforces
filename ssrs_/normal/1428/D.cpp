#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<pair<int, int>> ans;
  stack<int> st;
  int prev = -1;
  bool ok = true;
  for (int i = n - 1; i >= 0; i--){
    if (a[i] == 1){
      st.push(i);
      ans.push_back(make_pair(i + 1, i + 1));
    }
    if (a[i] == 2){
      if (st.empty()){
        ok = false;
        break;
      }
      ans.push_back(make_pair(st.top() + 1, i + 1));
      st.pop();
      prev = i;
    }
    if (a[i] == 3){
      if (prev == -1){
        if (st.empty()){
          ok = false;
          break;
        }
        ans.push_back(make_pair(i + 1, i + 1));
        ans.push_back(make_pair(i + 1, st.top() + 1));
        st.pop();
      } else {
        ans.push_back(make_pair(i + 1, i + 1));
        ans.push_back(make_pair(i + 1, prev + 1));
      }
      prev = i;
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    int t = ans.size();
    cout << t << endl;
    for (int i = 0; i < t; i++){
      cout << ans[i].first << ' ' << ans[i].second << endl;
    }
  }
}