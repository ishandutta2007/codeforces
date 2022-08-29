#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int sum = 0;
  bool ok = true;
  while (s.back() != '#'){
    if (s.back() == '('){
      sum--;
    }
    if (s.back() == ')'){
      sum++;
    }
    s.pop_back();
    if (sum < 0){
      ok = false;
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    int N = s.size();
    vector<int> ans;
    int c = 0;
    for (int i = 0; i < N - 1; i++){
      if (s[i]== '('){
        c++;
      }
      if (s[i] == ')'){
        c--;
      }
      if (s[i] == '#'){
        c--;
        ans.push_back(1);
      }
      if (c < 0){
        ok = false;
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else if (c <= sum){
      cout << -1 << endl;
    } else {
      ans.push_back(c - sum);
      for (int x : ans){
        cout << x << endl;
      }
    }
  }
}