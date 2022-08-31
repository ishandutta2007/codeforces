#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int n = s.size();
  stack<int> st1;
  multiset<char> st2;
  st1.push((char) ('z' + 1));
  st2.insert((char) ('z' + 1));
  for (int i = 0; i < n; i++){
    st2.insert(s[i]);
  }
  int p = 0;
  string ans;
  while (st1.size() > 1 || st2.size() > 1){
    if (st1.top() <= *st2.begin()){
      ans += st1.top();
      st1.pop();
    } else {
      if (p == n){
        break;
      }
      st2.erase(st2.find(s[p]));
      st1.push(s[p]);
      p++;
    }
  }
  cout << ans << endl;
}