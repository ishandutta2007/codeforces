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
    int c = 0, ac = 0, bc = 0;
    for (int j = 0; j < n; j++){
      if (a[j] == 1){
        ac++;
      }
      if (b[j] == 1){
        bc++;
      }
      if (a[j] != b[j]){
        c++;
      }
    }
    cout << min(c, abs(ac - bc) + 1) << endl;
  }
}