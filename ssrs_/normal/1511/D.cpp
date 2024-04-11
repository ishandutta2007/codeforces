#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  string s;
  for (int i = 0; i < k; i++){
    s += (char) ('a' + i);
    if (i > 0){
      s += (char) ('a' + i);
    }
  }
  for (int i = k - 2; i >= 0; i--){
    s += (char) ('a' + i);
    for (int j = i + 2; j < k; j++){
      s += (char) ('a' + j);
      s += (char) ('a' + i);
    }
  }
  int sz = s.size();
  string ans;
  for (int i = 0; i < n; i++){
    ans += s[i % sz];
  }
  cout << ans << endl;
}