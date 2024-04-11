#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    a[0] = 9;
    for (int j = 1; j < n; j++){
      a[j] = (j + 7) % 10;
    }
    for (int j = 0; j < n; j++){
      cout << a[j];
    }
    cout << endl;
  }
}