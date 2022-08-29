#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> x;
  for (int i = 1; i <= 9; i++){
    int t = 0;
    for (int j = 1; j <= 9; j++){
      t = t * 10 + i;
      x.push_back(t);
    }
  }
  sort(x.begin(), x.end());
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    cout << upper_bound(x.begin(), x.end(), n) - x.begin() << endl;
  }
}