#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int ans = 0;
    for (int j = 0; j < n; j++){
      for (int k = j + 1; k < n; k++){
        if (a[j] >= a[k]){
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
}