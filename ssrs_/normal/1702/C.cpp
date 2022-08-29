#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> u(n);
    for (int j = 0; j < n; j++){
      cin >> u[j];
    }
    map<int, int> mp1, mp2;
    for (int j = 0; j < n; j++){
      if (mp1.count(u[j]) == 0){
        mp1[u[j]] = j;
      }
      mp2[u[j]] = j;
    }
    for (int j = 0; j < k; j++){
      int a, b;
      cin >> a >> b;
      if (mp1.count(a) == 0 || mp1.count(b) == 0){
        cout << "NO" << "\n";
      } else {
        if (mp1[a] <= mp2[b]){
          cout << "YES" << "\n";
        } else {
          cout << "NO" << "\n";
        }
      }
    }
  }
}