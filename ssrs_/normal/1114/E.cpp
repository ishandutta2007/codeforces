#include <bits/stdc++.h>
using namespace std;
int main(){
  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  int n;
  cin >> n;
  int tv = 0, fv = 1000000000;
  while (fv - tv > 1){
    int mid = (tv + fv) / 2;
    cout << "> " << mid << endl;
    int ans;
    cin >> ans;
    if (ans == 0){
      fv = mid;
    } else {
      tv = mid;
    }
  }
  int mx = fv;
  vector<int> b(30);
  for (int i = 0; i < 30; i++){
    int p = mt() % n + 1;
    cout << "? " << p << endl;
    cin >> b[i];
  }
  int g = 0;
  for (int i = 1; i < 30; i++){
    g = __gcd(g, abs(b[i] - b[0]));
  }
  cout << "! " << mx - (n - 1) * g << ' ' << g << endl;
}