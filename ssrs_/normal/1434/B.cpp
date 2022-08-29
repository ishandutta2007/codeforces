#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> p(n * 2, -1);
  int cnt = 0;
  bool ok = true;
  for (int i = 0; i < n * 2; i++){
    char c;
    cin >> c;
    if (c == '-'){
      cin >> p[i];
      cnt--;
    } else {
      cnt++;
    }
    if (cnt < 0){
      ok = false;
    }
  }
  if (!ok){
    cout << "NO" << endl;
  } else {
    vector<int> a(n * 2, -1);
    stack<int> st;
    vector<int> ans;
    for (int i = n * 2 - 1; i >= 0; i--){
      if (p[i] == -1){
        a[i] = st.top();
        ans.push_back(a[i]);
        st.pop();
      } else {
        st.push(p[i]);
      }
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n * 2; i++){
      if (p[i] == -1){
        pq.push(a[i]);
      } else {
        if (pq.top() != p[i]){
          ok = false;
          break;
        } else {
          pq.pop();
        }
      }
    }
    if (!ok){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int i = n - 1; i >= 0; i--){
        cout << ans[i];
        if (i > 0){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}