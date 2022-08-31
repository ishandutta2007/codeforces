#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    string s(m, 'B');
    for (int j = 0; j < n; j++){
      a[j] = min(a[j], m - 1 - a[j]);
      if (s[a[j]] == 'B'){
        s[a[j]] = 'A';
      } else {
        s[m - 1 - a[j]] = 'A';
      }
    }
    cout << s << endl;
  }
}