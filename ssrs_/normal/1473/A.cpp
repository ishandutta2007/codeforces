#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    if (a[0] + a[1] <= d || a[n - 1] <= d){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}