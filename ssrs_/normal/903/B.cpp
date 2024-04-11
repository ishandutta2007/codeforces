#include <bits/stdc++.h>
using namespace std;
int main(){
  int h1, a1, c1;
  cin >> h1 >> a1 >> c1;
  int h2, a2;
  cin>> h2 >> a2;
  vector<string> ans;
  while (h2 > 0){
    if (h1 > a2 || h2 <= a1){
      ans.push_back("STRIKE");
      h2 -= a1;
    } else {
      ans.push_back("HEAL");
      h1 += c1;
    }
    h1 -= a2;
  }
  int n = ans.size();
  cout << n << endl;
  for (int i = 0; i < n; i++){
    cout << ans[i] << endl;
  }
}