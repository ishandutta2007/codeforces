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
    vector<vector<int>> p(101);
    for (int j = 0; j < n; j++){
      p[a[j]].push_back(j);
    }
    for (int j = 1; j <= 100; j++){
      if (p[j].size() == 1){
        cout << p[j][0] + 1 << endl;
      }
    }
  }
}