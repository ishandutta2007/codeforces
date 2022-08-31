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
    bool ok = true;
    map<pair<int, int>, int> A, B;
    for (int j = 0; j < n / 2; j++){
      A[make_pair(min(a[j], a[n - 1 - j]), max(a[j], a[n - 1 - j]))]++;
      B[make_pair(min(b[j], b[n - 1 - j]), max(b[j], b[n - 1 - j]))]++;
    }
    if (A != B){
      ok = false;
    }
    if (n % 2 == 1){
      if (a[n / 2] != b[n / 2]){
        ok = false;
      }
    }
    if (ok){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}