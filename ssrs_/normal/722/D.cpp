#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> y(n);
  for (int i = 0; i < n; i++){
    cin >> y[i];
  }
  set<int> x;
  for (int i = 0; i < n; i++){
    x.insert(y[i]);
  }
  priority_queue<int> q;
  for (int i = 0; i < n; i++){
    q.push(y[i]);
  }
  vector<int> ans;
  while (!q.empty()){
    int X = q.top();
    q.pop();
    int X2 = X;
    bool ok = false;
    while (X2 > 1){
      X2 /= 2;
      if (!x.count(X2)){
        ok = true;
        break;
      }
    }
    if (ok){
      q.push(X2);
      x.erase(X);
      x.insert(X2);
    } else {
      ans.push_back(X);
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