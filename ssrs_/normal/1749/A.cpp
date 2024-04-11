#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m);
    for (int j = 0; j < m; j++){
      cin >> x[j] >> y[j];
    }
    if (m < n){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}