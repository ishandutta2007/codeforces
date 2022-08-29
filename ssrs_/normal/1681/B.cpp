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
    int m;
    cin >> m;
    vector<int> b(m);
    for (int j = 0; j < m; j++){
      cin >> b[j];
    }
    long long sum = 0;
    for (int j = 0; j < m; j++){
      sum += b[j];
    }
    cout << a[sum % n] << endl;
  }
}