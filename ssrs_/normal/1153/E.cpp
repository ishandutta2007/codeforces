#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> r;
  for (int i = 0; i < n; i++){
    cout << "? " << i + 1 << ' ' << 1 << ' ' << i + 1 << ' ' << n << endl;
    int a;
    cin >> a;
    if (a % 2 == 1){
      r.push_back(i);
    }
  }
  vector<int> c;
  for (int i = 0; i < n; i++){
    cout << "? " << 1 << ' ' << i + 1 << ' ' << n << ' ' << i + 1 << endl;
    int a;
    cin >> a;
    if (a % 2 == 1){
      c.push_back(i);
    }
  }
  if (r.size() == 2 && c.size() == 2){
    cout << "? " << r[0] + 1 << ' ' << c[0] + 1 << ' ' << r[0] + 1 << ' ' << c[0] + 1 << endl;
    int a; 
    cin >> a;
    if (a % 2 == 1){
      cout << "! " << r[0] + 1 << ' ' << c[0] + 1 << ' ' << r[1] + 1 << ' ' << c[1] + 1 << endl;
    } else {
      cout << "! " << r[0] + 1 << ' ' << c[1] + 1 << ' ' << r[1] + 1 << ' ' << c[0] + 1 << endl;
    }
  }
  if (r.size() == 0){
    int tv = n - 1, fv = -1;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      cout << "? " << 1 << ' ' << 1 << ' ' << mid + 1 << ' ' << c[0] + 1 << endl;
      int a;
      cin >> a;
      if (a % 2 == 1){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << "! " << tv + 1 << ' ' << c[0] + 1 << ' ' << tv + 1 << ' ' << c[1] + 1 << endl;
  }
  if (c.size() == 0){
    int tv = n - 1, fv = -1;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      cout << "? " << 1 << ' ' << 1 << ' ' << r[0] + 1 << ' ' << mid + 1 << endl;
      int a;
      cin >> a;
      if (a % 2 == 1){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << "! " << r[0] + 1 << ' ' << tv + 1 << ' ' << r[1] + 1 << ' ' << tv + 1 << endl;
  }
}