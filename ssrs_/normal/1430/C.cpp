#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    stack<int> st;
    for (int j = 1; j <= n; j++){
      st.push(j);
    } 
    cout << 2 << endl;
    for (int j = 0; j < n - 1; j++){
      int a = st.top();
      st.pop();
      int b = st.top();
      st.pop();
      cout << a << ' ' << b << endl;
      st.push((a + b + 1) / 2);
    }
  }
}