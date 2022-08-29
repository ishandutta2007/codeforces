#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n * 2);
    for (int j = 0; j < n * 2; j++){
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    vector<int> b;
    for (int j = 0; j < n; j++){
      b.push_back(a[j]);
      b.push_back(a[n * 2 - 1 - j]);
    }
    for (int j = 0; j < n * 2; j++){
      cout << b[j];
      if (j < n * 2 - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}