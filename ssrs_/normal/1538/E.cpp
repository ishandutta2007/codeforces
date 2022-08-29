#include <bits/stdc++.h>
using namespace std;
struct var{
  long long haha;
  string s1, s2;
  var(){
  }
  var(string s){
    int N = s.size();
    haha = 0;
    for (int i = 0; i <= N - 4; i++){
      if (s.substr(i, 4) == "haha"){
        haha++;
      }
    }
    if (s.size() < 3){
      s1 = s;
      s2 = s;
    } else {
      s1 = s.substr(0, 3);
      s2 = s.substr(N - 3);
    }
  }
};
var operator +(var A, var B){
  var ans;
  if (A.s1.size() < 3 && B.s1.size() < 3){
    string s = A.s1 + B.s1;
    ans = s;
  } else if (A.s1.size() < 3){
    ans = B;
    string s = A.s1 + B.s1;
    var tmp = s;
    ans.haha += tmp.haha;
    ans.s1 = tmp.s1;
  } else if (B.s1.size() < 3){
    ans = A;
    string s = A.s2 + B.s1;
    var tmp = s;
    ans.haha += tmp.haha;
    ans.s2 = tmp.s2;
  } else {
    ans.haha = A.haha + B.haha;
    ans.s1 = A.s1;
    ans.s2 = B.s2;
    var tmp = A.s2 + B.s1;
    ans.haha += tmp.haha;
  }
  return ans;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    map<string, var> mp;
    for (int j = 0; j < n; j++){
      string v1;
      string op;
      cin >> v1 >> op;
      if (op == ":="){
        string s;
        cin >> s;
        mp[v1] = s;
      }
      if (op == "="){
        string v2, p, v3;
        cin >> v2 >> p >> v3;
        mp[v1] = mp[v2] + mp[v3];
      }
      if (j == n - 1){
        cout << mp[v1].haha << endl;
      }
    }
  }
}