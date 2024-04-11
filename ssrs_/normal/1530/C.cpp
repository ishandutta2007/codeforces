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
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    int tv = n * 2, fv = -1;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      vector<int> a2 = a, b2 = b;
      for (int j = 0; j < mid; j++){
        a2.push_back(100);
        b2.push_back(0);
      }
      sort(a2.begin(), a2.end(), greater<int>());
      sort(b2.begin(), b2.end(), greater<int>());
      int sa = 0;
      int sb = 0;
      for (int j = 0; j < n + mid - (n + mid) / 4; j++){
        sa += a2[j];
        sb += b2[j];
      }
      if (sa >= sb){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}