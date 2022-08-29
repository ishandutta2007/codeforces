#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> b(n + 2);
    for (int j = 0; j < n + 2; j++){
      cin >> b[j];
    }
    long long sum = 0;
    for (int j = 0; j < n + 2; j++){
      sum += b[j];
    }
    vector<pair<int, int>> mxL(n + 3);
    mxL[0] = make_pair(0, 0);
    for (int j = 0; j < n + 2; j++){
      mxL[j + 1] = max(mxL[j], make_pair(b[j], j));
    }
    vector<pair<int, int>> mxR(n + 3);
    mxR[n + 2] = make_pair(0, 0);
    for (int j = n + 1; j >= 0; j--){
      mxR[j] = max(mxR[j + 1], make_pair(b[j], j));
    }
    int p1 = -1, p2 = -1;
    for (int j = 0; j < n + 2; j++){
      long long sum2 = sum - b[j];
      long long mx = max(mxL[j].first, mxR[j + 1].first);
      if (mx * 2 == sum2){
        p1 = j;
        if (mxL[j].first > mxR[j + 1].first){
          p2 = mxL[j].second;
        } else {
          p2 = mxR[j + 1].second;
        }
      }
    }
    if (p1 == -1 && p2 == -1){
      cout << -1 << endl;
    } else {
      vector<int> a;
      for (int j = 0; j < n + 2; j++){
        if (j != p1 && j != p2){
          a.push_back(b[j]);
        }
      }
      for (int j = 0; j < n; j++){
        cout << a[j];
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}