#include <bits/stdc++.h>
using namespace std;
string num_min(string A, string B){
  if (A.size() < B.size() || A.size() == B.size() && A < B){
    return A;
  } else {
    return B;
  }
}
string add(string A, string B){
  bool carry = false;
  string ans;
  while (A != "" || B != "" || carry){
    int next = 0;
    if (A != ""){
      next += A.back() - '0';
      A.pop_back();
    }
    if (B != ""){
      next += B.back() - '0';
      B.pop_back();
    }
    if (carry){
      next++;
    }
    ans += '0' + next % 10;
    if (next >= 10){
      carry = true;
    } else {
      carry = false;
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
int main(){
  int l;
  cin >> l;
  string n;
  cin >> n;
  string ans = n;
  for (int i = l / 2 + 1; i < l; i++){
    if (n[i] != '0'){
      ans = num_min(ans, add(n.substr(0, i), n.substr(i)));
      break;
    }
  }
  for (int i = l / 2; i >= 0; i--){
    if (n[i] != '0'){
      ans = num_min(ans, add(n.substr(0, i), n.substr(i)));
      break;
    }
  }
  cout << ans << endl;
}