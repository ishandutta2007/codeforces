#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<string> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    vector<int> c(3, 0);
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        if (s[j][k] == 'X'){
          c[(j + k) % 3]++;
        }
      }
    }
    int r = min_element(c.begin(), c.end()) - c.begin();
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        if (s[j][k] == 'X'){
          if ((j + k) % 3 == r){
            s[j][k] = 'O';
          }
        }
      }
    }
    for (int j = 0; j < n; j++){
      cout << s[j] << endl;
    }
  }
}