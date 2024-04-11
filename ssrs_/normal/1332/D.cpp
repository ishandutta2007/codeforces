#include <bits/stdc++.h>
using namespace std;
int main(){
  int k;
  cin >> k;
  int x = 262143;
  cout << 3 << ' ' << 3 << endl;
  cout << x << ' ' << k << ' ' << x - k << endl;
  cout << x - k << ' ' << x << ' ' << k << endl;
  cout << x - k << ' ' << k << ' ' << x << endl;
}