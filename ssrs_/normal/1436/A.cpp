#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int sum = 0;
    for (int j = 0; j < n; j++){
      sum += a[j];
    }
    if (sum == m){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}