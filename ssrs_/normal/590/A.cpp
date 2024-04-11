#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int mx = 1;
  int curr = 1;
  for (int i = 1; i < n; i++){
    if (a[i - 1] != a[i]){
      curr++;
      mx = max(mx, curr);
    } else {
      curr = 1;
    }
  }
  cout << (mx - 1) / 2 << endl;
  vector<int> same;
  same.push_back(0);
  for (int i = 1; i < n; i++){
    if (a[i - 1] == a[i]){
      same.push_back(i);
    }
  }
  same.push_back(n);
  vector<int> ans(n);
  for (int i = 0; i < n; i++){
    auto itr1 = upper_bound(same.begin(), same.end(), i) - 1;
    auto itr2 = upper_bound(same.begin(), same.end(), i);
    int x = *itr1;
    int y = *itr2;
    if ((i - x) < (y - i)){
      ans[i] = a[x];
    } else {
      ans[i] = a[y - 1];
    }
  }
  for (int i = 0; i < n; i++){
    cout << ans[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}