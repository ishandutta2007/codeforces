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
    int l = n, r = 0, c = 0;
    for (int j = 0; j < n; j++){
      if (a[j] == 1){
        l = min(l, j);
        r = max(r, j);
        c++;
      }
    }
    cout << (r - l) - c + 1 << endl;
  }
}