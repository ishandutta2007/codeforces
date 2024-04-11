#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  cout << fixed << setprecision(20);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int W, H;
    cin >> W >> H;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w, h;
    cin >> w >> h;
    int ans = INF;
    if (x2 - x1 + w <= W){
      ans = min(ans, max(w - x1, 0));
      ans = min(ans, max(x2 - (W - w), 0));
    }
    if (y2 - y1 + h <= H){
      ans = min(ans, max(h - y1, 0));
      ans = min(ans, max(y2 - (H - h), 0));
    }
    if (ans == INF){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}