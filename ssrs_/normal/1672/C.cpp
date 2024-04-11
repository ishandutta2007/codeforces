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
    vector<int> p;
    for (int j = 0; j < n - 1; j++){
      if (a[j] == a[j + 1]){
        p.push_back(j);
      }
    }
    if (p.size() <= 1){
      cout << 0 << endl;
    } else if (p.size() == 2 && p[1] - p[0] == 1){
      cout << 1 << endl;
    } else {
      cout << p[p.size() - 1] - p[0] - 1 << endl;
    }
  }
}