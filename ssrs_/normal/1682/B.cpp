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
    int ans = (1 << 20) - 1;
    for (int j = 0;  j < n; j++){
      if (p[j] != j){
        ans &= p[j];
      }
    }
    cout << ans << endl;
  }
}