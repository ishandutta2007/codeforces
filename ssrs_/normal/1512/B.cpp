#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<string> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    set<int> x, y;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        if (s[j][k] == '*'){
          x.insert(j);
          y.insert(k);
        }
      }
    }
    if (x.size() == 1){
      x.insert((*x.begin() + 1) % n);
    }
    if (y.size() == 1){
      y.insert((*y.begin() + 1) % n);
    }
    for (int a : x){
      for (int b : y){
        s[a][b] = '*';
      }
    }
    for (int j = 0; j < n; j++){
      cout << s[j] << endl;
    }
  }
}