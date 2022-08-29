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
    bool flgN = false;
    bool flgP = false;
    bool flg = true;
    for (int j = 0; j < n; j++){
      if (b[j] > a[j] && !flgP){
        flg = false;
      }
      if (b[j] < a[j] && !flgN){
        flg = false;
      }
      if (a[j] == 1){
        flgP = true;
      }
      if (a[j] == -1){
        flgN = true;
      }
    }
    if (flg){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}