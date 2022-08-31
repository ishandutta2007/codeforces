#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int j = 0; j < n; j++){
      cin >> x[j] >> y[j];
    }
    if (n % 2 == 1){
      cout << 1 << endl;
    } else {
      sort(x.begin(), x.end());
      sort(y.begin(), y.end());
      long long A = x[n / 2] - x[n / 2 - 1] + 1;
      long long B = y[n / 2] - y[n / 2 - 1] + 1;
      cout << A * B << endl;
    }
  }
}