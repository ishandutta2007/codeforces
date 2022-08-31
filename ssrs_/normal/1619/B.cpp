#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> A;
  int x = 1;
  while (x * x <= 1000000000){
    A.push_back(x * x);
    x++;
  }
  int y = 1;
  while (y * y * y <= 1000000000){
    A.push_back(y * y * y);
    y++;
  }
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    cout << upper_bound(A.begin(), A.end(), n) - A.begin() << endl;
  }
}