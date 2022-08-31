#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
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
    vector<int> P;
    for (int j = 1; j < n - 1; j++){
      if (a[j - 1] < a[j] && a[j] > a[j + 1]){
        P.push_back(j);
      }
    }
    int cnt = P.size();
    int m = 0;
    for (int j = 0; j < cnt; j++){
      if (a[P[j] - 1] < a[P[j]] && a[P[j]] > a[P[j] + 1]){
        if (P[j] < n - 2){
          a[P[j] + 1] = max(a[P[j]], a[P[j] + 2]);
        } else {
          a[P[j] + 1] = a[P[j]];
        }
        m++;
      }
    }
    cout << m << endl;
    for (int j = 0; j < n; j++){
      cout << a[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}