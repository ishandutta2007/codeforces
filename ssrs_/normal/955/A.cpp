#include <bits/stdc++.h>
using namespace std;
int main(){
  cout << fixed << setprecision(4);
  int hh, mm;
  cin >> hh >> mm;
  int t = (hh * 60 + mm) - (20 * 60);
  int H, D, C, N;
  cin >> H >> D >> C >> N;
  double C2 = C * (1 - 0.2);
  if (t > 0){
    cout << (H + N - 1) / N * C2 << endl;
  } else {
    double ans1 = (H + N - 1) / N * C;
    double ans2 = (H - D * t + N - 1) / N * C2;
    cout << min(ans1, ans2) << endl;
  }
}