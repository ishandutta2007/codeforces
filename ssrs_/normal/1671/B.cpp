#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> x(n);
    for (int j = 0; j < n; j++){
      cin >> x[j];
    }
    if (x[n - 1] - x[0] <= n + 1){
      cout << "YES" << endl;
    } else {
      cout << "NO "<< endl;
    }
  }
}