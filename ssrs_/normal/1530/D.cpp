#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<bool> used(n, false);
    int k = 0;
    vector<int> pos;
    vector<int> t;
    for (int j = 0; j < n; j++){
      if (!used[a[j]]){
        k++;
        used[a[j]] = true;
      } else {
        t.push_back(a[j]);
        a[j] = -1;
        pos.push_back(j);
      }
    }
    vector<int> X;
    for (int j = 0; j < n; j++){
      if (!used[j]){
        X.push_back(j);
      }
    }
    int cnt = X.size();
    if (pos.size() == 1 && cnt == 1){
      if (pos[0] == X[0]){
        int p;
        for (int j = 0; j < n; j++){
          if (a[j] == t[0]){
            p = j;
            break;
          }
        }
        a[X[0]] = t[0];
        a[p] = -1;
        pos[0] = p;
      }
    }
    for (int j = 0; j < cnt; j++){
      if (pos[j] == X.back()){
        a[pos[j]] = X[X.size() - 2];
        X.erase(X.end() - 2);
      } else if (j == cnt - 2 && pos[cnt - 1] == X[0]){
        a[pos[j]] = X[0];
        X.erase(X.begin());
      } else {
        a[pos[j]] = X.back();
        X.pop_back();
      }
    }
    cout << k << endl;
    for (int j = 0; j < n; j++){
      cout << a[j] + 1;
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}