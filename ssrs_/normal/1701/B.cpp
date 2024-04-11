#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p;
    vector<bool> used(n + 1, false);
    for (int j = 1; j <= n; j++){
      if (!used[j]){
        for (int k = j; k <= n; k *= 2){
          used[k] = true;
          p.push_back(k);
        }
      }
    }
    cout << 2 << endl;
    for (int j = 0; j < n; j++){
      cout << p[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}