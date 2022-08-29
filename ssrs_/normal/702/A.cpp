#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int ans = 1;
  int curr = 1;
  for (int i = 1; i < n; i++){
    if (a[i] > a[i - 1]){
      curr++;
      ans = max(ans, curr);
    } else {
      curr = 1;
    }
  }
  cout << ans << endl;
}