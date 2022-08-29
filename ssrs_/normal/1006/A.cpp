#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    if (a[i] % 2 == 0){
      b[i] = a[i] - 1;
    } else {
      b[i] = a[i];
    }
  }
  for (int i = 0; i < n; i++){
    cout << b[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}