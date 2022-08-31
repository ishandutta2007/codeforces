#include <bits/stdc++.h>
using namespace std;
int main(){
  int k;
  cin >> k;
  cin.ignore();
  string s;
  getline(cin, s);
  int m = s.size();
  vector<int> c = {0};
  for (int i = 0; i < m; i++){
    if (isalpha(s[i])){
      c.back()++;
    } else {
      c.push_back(0);
    }
  }
  int n = c.size();
  int mx = 0;
  for (int i = 0; i < n - 1; i++){
    mx = max(mx, c[i] + 1);
  }
  mx = max(mx, c[n - 1]);
  int tv = m, fv = mx - 1;
  while (tv - fv > 1){
    int mid = (tv + fv) / 2;
    int r = 0, cnt = 1;
    for (int i = 0; i < n; i++){
      int r2 = r + c[i];
      if (i < n - 1){
        r2++;
      }
      if (r2 <= mid){
        r = r2;
      } else {
        cnt++;
        r = r2 - r;
      }
    }
    if (cnt <= k){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv << endl;
}