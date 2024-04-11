#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    int minadj = 2000000000;
    int maxadj = -1;
    int maxdiff = -1;
    for (int i = 0; i < n; i++){
      if (a[i] == -1){
        if (i != 0){
          if (a[i - 1] != -1){
            minadj = min(minadj,a[i - 1]);
            maxadj = max(maxadj,a[i - 1]);
          }
        }
        if (i != n - 1){
          if (a[i + 1] != -1){
            minadj = min(minadj,a[i + 1]);
            maxadj = max(maxadj,a[i + 1]);
          }
        }
      } else {
        if (i != 0){
          if (a[i - 1] != -1){
            maxdiff = max(maxdiff,abs(a[i] - a[i - 1]));
          }
        }
      }
    }
    if (minadj == 2000000000){
      cout << 0 << ' ' << 1 << endl;
      continue;
    }
    int k = (minadj + maxadj) / 2;
    int diff = max(k - minadj, maxadj - k);
    int m = max(diff,maxdiff);
    cout << m << ' ' << k << endl;
  }
}