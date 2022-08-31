#include <bits/stdc++.h>
using namespace std;
vector<int> A = {1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000};
int main(){
  int r;
  cin >> r;
  cout << *upper_bound(A.begin(), A.end(), r) << endl;
}