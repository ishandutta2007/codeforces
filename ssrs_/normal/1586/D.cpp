#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> A(n * 2 - 1);
  for (int i = n; i >= 1; i--){
    vector<int> a(n, i);
    a[n - 1] = 1;
    cout << "?";
    for (int j = 0; j < n; j++){
      cout << ' ' << a[j];
    }
    cout << endl;
    cin >> A[n - i];
    A[n - i]--;
  }
  for (int i = 2; i <= n; i++){
    vector<int> a(n, 1);
    a[n - 1] = i;
    cout << "?";
    for (int j = 0; j < n; j++){
      cout << ' ' << a[j];
    }
    cout << endl;
    cin >> A[n + i - 2];
    A[n + i - 2]--;
  }
  for (int i = 0; i < n; i++){
    vector<bool> used(n * 2 - 1, false);
    for (int j = 0; j < n; j++){
      if (j != i){
        used[j - i + n - 1] = true;
      }
    }
    bool ok = true;
    for (int j = 0; j < n * 2 - 1; j++){
      if (used[j] && A[j] == -1){
        ok = false;
      }
    }
    if (ok){
      vector<int> p(n);
      p[n - 1] = i;
      for (int j = 0; j < n; j++){
        if (j != i){
          p[A[j - i + n - 1]] = j;
        }
      }
      cout << "!";
      for (int j = 0; j < n; j++){
        cout << ' ' << p[j] + 1;
      }
      cout << endl;
    }
  }
}