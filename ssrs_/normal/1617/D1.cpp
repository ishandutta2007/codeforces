#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> r(n);
    for (int j = 0; j < n; j++){
      int a = j, b = (j + 1) % n, c = (j + 2) % n;
      cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
      cin >> r[j];
    }
    int p;
    for (int j = 0; j < n; j++){
      if (r[j] == 0 && r[(j + 1) % n] == 1){
        p = j;
      }
    }
    vector<int> ans;
    ans.push_back(p);
    for (int j = 0; j < n; j++){
      if (j != p && j != (p + 3) % n){
        cout << "? " << j + 1 << ' ' << p + 1 << ' ' << (p + 3) % n + 1 << endl;
        int res;
        cin >> res;
        if (res == 0){
          ans.push_back(j);
        }
      }
    }
    int k = ans.size();
    cout << "! " << k;
    for (int j = 0; j < k; j++){
      cout << ' ' << ans[j] + 1;
    }
    cout << endl;
  }
}