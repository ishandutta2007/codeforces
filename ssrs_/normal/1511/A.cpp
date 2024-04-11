#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> r(n);
    for (int j = 0; j < n; j++){
      cin >> r[j];
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      if (r[j] == 1 || r[j] == 3){
        ans++;
      }
    }
    cout << ans << endl;
  }
}