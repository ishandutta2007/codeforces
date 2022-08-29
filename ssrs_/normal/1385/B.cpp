#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n * 2);
    for (int j = 0; j < n * 2; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<bool> used(n, false);
    vector<int> p;
    for (int j = 0; j < n * 2; j++){
      if (!used[a[j]]){
        p.push_back(a[j]);
        used[a[j]] = true;
      }
    }
    for (int j = 0; j < n; j++){
      cout << p[j] + 1;
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}