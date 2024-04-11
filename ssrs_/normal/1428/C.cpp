#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    stack<char> st;
    st.push('_');
    for (int j = 0; j < n; j++){
      if (s[j] == 'A'){
        st.push('A');
      } else {
        if (st.top() != '_'){
          st.pop();
        } else {
          st.push('B');
        }
      }
    }
    cout << st.size() - 1 << endl;
  }
}