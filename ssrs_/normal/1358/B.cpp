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
    sort(a.begin(), a.end());
    int ans = 0;
    for (int j = 0; j < n; j++){
      if (a[j] <= j + 1){
        ans = j + 1;
      }
    }
    cout << ans + 1 << endl;
  }
}