#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  for (int i = 0; i < n; i++){
    while (a[i] % 2 == 0){
      a[i] /= 2;
    }
    while (a[i] % 3 == 0){
      a[i] /= 3;
    }
  }
  sort(a.begin(), a.end());
  if (a[0] == a[n - 1]){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}