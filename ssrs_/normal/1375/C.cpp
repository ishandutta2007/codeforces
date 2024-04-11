#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    stack<int> st;
    for (int j = 0; j < n; j++){
      if (st.empty()){
        st.push(a[j]);
      } else {
        if (st.top() > a[j]){
          st.push(a[j]);
        } else {
          int tmp = a[j];
          while (st.top() < a[j]){
            tmp = st.top();
            st.pop();
            if (st.empty()){
              break;
            }
          }
          st.push(tmp);
        }
      }
    }
    if (st.size() == 1){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}