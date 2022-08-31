#include <bits/stdc++.h>
using namespace std;
const int INF = 100000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, H, M;
    cin >> n >> H >> M;
    vector<int> h(n), m(n);
    for (int j = 0; j < n; j++){
      cin >> h[j] >> m[j];
    }
    int ct = H * 60 + M;
    int ans = INF;
    for (int j = 0; j < n; j++){
      int t2 = h[j] * 60 + m[j];
      if (t2 >= ct){
        ans = min(ans, t2 - ct);
      } else {
        ans = min(ans, t2 + 1440 - ct);
      }
    }
    cout << ans / 60 << ' ' << ans % 60 << endl;
  }
}