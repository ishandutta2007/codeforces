#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    int m = 1;
    while (m * 2 < n){
      m *= 2;
    }
    vector<int> p;
    for (int j = m - 1; j >= 0; j--){
      p.push_back(j);
    }
    for (int j = m; j < n; j++){
      p.push_back(j);
    }
    for (int j = 0; j < n; j++){
      cout << p[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}