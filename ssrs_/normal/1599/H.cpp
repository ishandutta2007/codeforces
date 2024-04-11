#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1000000000;
int main(){
  cout << "? " << 1 << ' ' << 1 << endl;
  int A1;
  cin >> A1;
  cout << "? " << 1 << ' ' << MAX << endl;
  int A2;
  cin >> A2;
  cout << "? " << MAX << ' ' << MAX << endl;
  int A3;
  cin >> A3;
  int l = (MAX + 1 + A1 - A2) / 2;
  cout << "? " << 1 << ' ' << l << endl;
  int L;
  cin >> L;
  cout << "? " << MAX << ' ' << l << endl;
  int R;
  cin >> R;
  int u = (MAX + 1 + A2 - A3) / 2;
  cout << "? " << u << ' ' << 1 << endl;
  int D;
  cin >> D;
  cout << "? " << u << ' ' << MAX << endl;
  int U;
  cin >> U;
  int x = L + 1;
  int y = D + 1;
  int p = MAX - R;
  int q = MAX - U;
  cout << "! " << x << ' ' << y << ' ' << p << ' ' << q << endl;
}