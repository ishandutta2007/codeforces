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
    string s;
    cin >> s;
    vector<int> b, r;
    for (int j = 0; j < n; j++){
      if (s[j] == 'B'){
        b.push_back(a[j]);
      }
      if (s[j] == 'R'){
        r.push_back(a[j]);
      }
    }
    int B = b.size();
    int R = r.size();
    bool ok = true;
    sort(b.begin(), b.end());
    for (int j = 0; j < B; j++){
      if (b[j] <= j){
        ok = false;
      }
    }
    sort(r.begin(), r.end(), greater<int>());
    for (int j = 0; j < R; j++){
      if (r[j] > n - j){
        ok = false;
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}