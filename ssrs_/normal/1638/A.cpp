#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    for (int j = 0; j < n; j++){
      if (p[j] != j){
        for (int k = j + 1; k < n; k++){
          if (p[k] == j){
            reverse(p.begin() + j, p.begin() + k + 1);
            break;
          }
        }
        break;
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