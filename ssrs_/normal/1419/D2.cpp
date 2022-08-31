#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> b, c;
  for (int i = 0; i < n / 2; i++){
    b.push_back(a[i]);
  }
  for (int i = n / 2; i < n; i++){
    c.push_back(a[i]);
  }
  vector<int> ans(n);
  for (int i = 0; i < n; i++){
    if (i % 2 == 0){
      ans[i] = c[i / 2];
    } else {
      ans[i] = b[i / 2];
    }
  }
  int cnt = 0;
  for (int i = 1; i < n - 1; i++){
    if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]){
      cnt++;
    }
  }
  cout << cnt << endl;
  for (int i = 0; i < n; i++){
    cout << ans[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}