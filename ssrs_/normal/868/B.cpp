#include <bits/stdc++.h>
using namespace std;
int main(){
  double h, m, s, t1, t2;
  cin >> h >> m >> s >> t1 >> t2;
  if (t1 == t2){
    cout << "YES" << endl;
  } else {
    vector<double> t = {h / 12, m / 60, s / 60};
    sort(t.begin(), t.end());
    int p = lower_bound(t.begin(), t.end(), t1 / 12) - t.begin();
    int q = lower_bound(t.begin(), t.end(), t2 / 12) - t.begin();
    if (p == q || p == 0 && q == 3 || p == 3 && q == 0){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}