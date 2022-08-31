#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int N = s.size();
  stack<pair<int, int>> st;
  for (int i = 0; i < N; i++){
    pair<int, int> P = make_pair(i, s[i] - '0');
    if (st.empty()){
      st.push(P);
    } else if (s[i] == '1'){
      st.push(P);
    } else if (st.top().second == 0){
      st.push(P);
    } else {
      st.pop();
    }
  }
  while (!st.empty()){
    s[st.top().first] = '0';
    st.pop();
  }
  cout << s << endl;
}