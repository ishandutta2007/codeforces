#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int w, h;
    cin >> w >> h;
    int k1;
    cin >> k1;
    vector<int> x1(k1);
    for (int j = 0; j < k1; j++){
      cin >> x1[j];
    }
    int k2;
    cin >> k2;
    vector<int> x2(k2);
    for (int j = 0; j < k2; j++){
      cin >> x2[j];
    }
    int k3;
    cin >> k3;
    vector<int> y1(k3);
    for (int j = 0; j < k3; j++){
      cin >> y1[j];
    }
    int k4;
    cin >> k4;
    vector<int> y2(k4);
    for (int j = 0; j < k4; j++){
      cin >> y2[j];
    }
    long long ans = 0;
    ans = max(ans, (long long) (x1[k1 - 1] - x1[0]) * h);
    ans = max(ans, (long long) (x2[k2 - 1] - x2[0]) * h);
    ans = max(ans, (long long) (y1[k3 - 1] - y1[0]) * w);
    ans = max(ans, (long long) (y2[k4 - 1] - y2[0]) * w);
    cout << ans << endl;
  }
}