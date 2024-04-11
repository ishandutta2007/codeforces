#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
    }
    vector<int> c;
    c.push_back(0);
    for (int j = 1; j < n; j++){
      if (p[j] != p[j - 1]){
        c.push_back(j);
      }
    }
    int sum_max = 0;
    int g = 0, s = 0, b = 0;
    for (int j : c){
      if (j == 0){
        continue;
      }
      int g2 = j;
      auto itr1 = upper_bound(c.begin(), c.end(), g2 + j);
      if (itr1 == c.end()){
        continue;
      }
      int s2 = *itr1 - g2;
      auto itr2 = upper_bound(c.begin(), c.end(), n / 2) - 1;
      if (*itr2 > g2 + s2 + j){
        int b2 = *itr2 - g2 - s2;
        if (sum_max < g2 + s2 + b2){
          sum_max = g2 + s2 + b2;
          g = g2;
          s = s2;
          b = b2;
        }
      }
    }
    cout << g << ' ' << s << ' ' << b << endl;
  }
}