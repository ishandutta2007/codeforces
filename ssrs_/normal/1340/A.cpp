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
    }
    bool res = true;
    for (int j = 0; j < n - 1; j++){
      if (p[j + 1] > p[j] + 1){
        res = false;
      }
    }
    if (res){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}