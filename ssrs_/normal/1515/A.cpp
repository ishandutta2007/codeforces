#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int j = 0; j < n; j++){
      cin >> w[j];
    }
    sort(w.begin(), w.end());
    int sum = 0;
    for (int j = 0; j < n; j++){
      sum += w[j];
    }
    if (sum == x){
      cout << "NO" << endl;
    } else {
      int csum = 0;
      vector<int> ans;
      for (int j = 0; j < n; j++){
        if (csum + w[j] == x){
          int tmp = w[n - 1];
          w.insert(w.begin() + j, tmp);
          w.pop_back();
        }
        csum += w[j];
      }
      cout << "YES" << endl;
      for (int j = 0; j < n; j++){
        cout << w[j];
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}