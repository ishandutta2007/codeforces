#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> M;
    for (int j = 0; j < n; j++){
      cin >> a[j];
      M[a[j]]++;
    }
    int F = 0;
    int C = 0;
    for (auto P : M){
      F = max(F, P.second);
      C++;
    }
    if (F != C){
      cout << min(F, C) << endl;
    } else {
      cout << F - 1 << endl;
    }
  }
}