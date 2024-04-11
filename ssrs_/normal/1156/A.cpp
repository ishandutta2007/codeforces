#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  bool inf = false;
  int ans = 0;
  for (int i = 0; i < n - 1; i++){
    if (a[i] == 1 && a[i + 1] == 2 || a[i] == 2 && a[i + 1] == 1){
      ans += 3;
    } else if (a[i] == 1 && a[i + 1] == 3 || a[i] == 3 && a[i + 1] == 1){
      ans += 4;
    } else {
      inf = true;
    }
  }
  for (int i = 0; i < n - 2; i++){
    if (a[i] == 3 && a[i + 1] == 1 && a[i + 2] == 2){
      ans--;
    }
  }
  if (inf){
    cout << "Infinite" << endl;
  } else {
    cout << "Finite" << endl;
    cout << ans << endl;
  }
}