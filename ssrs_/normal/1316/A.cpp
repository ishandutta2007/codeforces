#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++){
      cin >> a[i];
      if (i > 0) sum += a[i];
    }
    if (sum >= m - a[0]){
      cout << m << endl;
    } else {
      cout << a[0] + sum << endl;
    }
  }
}