#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> c;
  int curr = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == 'x'){
      curr++;
    } else {
      c.push_back(curr);
      curr = 0;
    }
  }
  if (curr > 0){
    c.push_back(curr);
  }
  int m = c.size();
  int ans = 0;
  for (int i = 0; i < m; i++){
    ans += max(c[i] - 2, 0);
  }
  cout << ans << endl;
}