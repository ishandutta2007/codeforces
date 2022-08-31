#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<bool> k(n + 1, true);
  for (int i = 1; i <= n; i++){
    //k = i
    vector<int> x(i);
    x[0] = a[0];
    for (int j = 1; j < i; j++){
      x[j] = a[j] - a[j - 1];
    }
    for (int j = i; j < n; j++){
      int tmp = a[j] - a[j - 1];
      if (tmp != x[j % i]){
        k[i] = false;
      }
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++){
    if (k[i]){
      ans.push_back(i);
    }
  }
  int l = ans.size();
  cout << l << endl;
  for (int i = 0; i < l; i++){
    cout << ans[i];
    if (i < l - 1){
      cout << ' ';
    }
  }
  cout << endl;
}