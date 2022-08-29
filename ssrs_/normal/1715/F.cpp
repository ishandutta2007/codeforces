#include <bits/stdc++.h>
using namespace std;
const double eps = 0.00000001;
int main(){
  cout << fixed << setprecision(12);
  int n, m;
  cin >> n >> m;
  if (n == 1){
    cout << "? " << 3 << endl;
    cout << 0 << ' ' << 0 << endl;
    cout << 0 << ' ' << m << endl;
    cout << 1 << ' ' << m << endl;
    double s;
    cin >> s;
    double y = (s * m * 2 - 1) / 2;
    cout << "! " << 0 << ' ' << y << endl;
  } else if (m == 1){
    cout << "? " << 3 << endl;
    cout << 0 << ' ' << 0 << endl;
    cout << n << ' ' << 0 << endl;
    cout << n << ' ' << 1 << endl;
    double s;
    cin >> s;
    double x = (s * n * 2 - 1) / 2;
    cout << "! " << x << ' ' << 0 << endl;
  } else {
    cout << "? " << m * 2 + 2 << endl;
    cout << 0 << ' ' << 0 << endl;
    for (int i = 0; i < m; i++){
      cout << n << ' ' << i << endl;
      cout << 1 << ' ' << i + 1 << endl;
    }
    cout << 0 << ' ' << m << endl;
    double s1;
    cin >> s1;
    cout << "? " << n * 2 + 2 << endl;
    cout << 0 << ' ' << 0 << endl;
    for (int i = 0; i < n; i++){
      cout << i << ' ' << m << endl;
      cout << i + 1 << ' ' << 1 << endl;
    }
    cout << n << ' ' << 0 << endl;
    double s2;
    cin >> s2;
    double x, y;
    if (s1 < (double) (n * 2 - 3) / (n * 2 - 2)){
      x = n - 1 - (s1 * (n - 1) * 2 - 1) / 2;
    } else {
      s1 = (1 - s1) * (n * 2 - 2);
      x = sqrt(max(s1, (double) 0));
    }
    if (s2 < (double) (m * 2 - 3) / (m * 2 - 2)){
      y = m - 1 - (s2 * (m - 1) * 2 - 1) / 2;
    } else {
      s2 = (1 - s2) * (m * 2 - 2);
      y = sqrt(max(s2, (double) 0));
    }
    cout << "! " << x << ' ' << y << endl;
  }
}