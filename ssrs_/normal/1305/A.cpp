#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++){
      cout << a[i] << ' ';
    }
    cout << endl;
    vector<int> b(n);
    for (int i = 0; i < n; i++){
      cin >> b[i];
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++){
      cout << b[i] << ' ';
    }
    cout << endl;
  }
}