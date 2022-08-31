#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
int main(){
  cout << fixed << setprecision(20);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    double n;
    cin >> n;
    double ans = 0;
    for (int j = 0; j < n / 2; j++){
      ans = max(ans, sin(PI / 4 + PI / n * j) / sin(PI / (n * 2)));
    }
    cout << ans << endl;
  }
}