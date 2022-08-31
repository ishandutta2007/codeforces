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
    vector<int> l(n);
    for (int j = 0; j < n; j++){
      cin >> l[j];
    }
    vector<int> b;
    for (int j = 0; j < n; j++){
      if (l[j] == 0){
        b.push_back(a[j]);
      }
    }
    sort(b.rbegin(), b.rend());
    int p = 0;
    for (int j = 0; j < n; j++){
      if (l[j] == 0){
        a[j] = b[p];
        p++;
      }
    }
    for (int j = 0; j < n; j++){
      cout << a[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}