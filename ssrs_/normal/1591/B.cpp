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
    int cnt = 0;
    int mx = a[n - 1];
    for (int j = n - 1; j >= 0; j--){
      if (a[j] > mx){
        mx = a[j];
        cnt++;
      }
    }
    cout << cnt << endl;
  }
}