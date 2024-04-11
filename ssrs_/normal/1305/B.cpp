#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int n = s.size();
  bool flg = false;
  for (int i = 0; i < n - 1; i++){
    if (s[i] == '(' && s[i + 1] == ')'){
      flg = true;
    }
  }
  if (!flg){
    cout << 0;
  } else {
    int count = 0;
    vector<int> L(n);
    for (int i = 0; i < n; i++){
      if (s[i] == '('){
        count++;
      }
      L[i] = count;
    }
    count = 0;
    vector<int> R(n);
    for (int i = n - 1; i >= 0; i--){
      if (s[i] == ')'){
        count++;
      }
      R[i] = count;
    }
    int p = 0;
    for (int i = 0; i < n - 1; i++){
      if (L[i] == R[i + 1]){ 
        p = i;
        break;
      }
    }
    vector<int> d;
    for (int i = 0; i <= p; i++){
      if (s[i] == '('){
        d.push_back(i);
      }
    }
    for (int i = p + 1; i < n; i++){
      if (s[i] == ')'){
        d.push_back(i);
      }
    }
    cout << 1 << endl;
    cout << d.size() << endl;
    for (int i = 0; i < d.size(); i++){
      cout << d[i] + 1 << ' ';
    }
  }
}