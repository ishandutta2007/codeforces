#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    if (n % 2 == 1){
      cout << "Mike" << endl;
    } else {
      vector<int> mn(2, INF);
      for (int j = 0; j < n; j++){
        mn[j % 2] = min(mn[j % 2], a[j]);
      }
      if (mn[0] > mn[1]){
        cout << "Mike" << endl;
      } else if (mn[0] < mn[1]){
        cout << "Joe" << endl;
      } else {
        vector<int> p(2, -1);
        for (int j = 0; j < n; j++){
          if (a[j] == mn[j % 2] && p[j % 2] == -1){
            p[j % 2] = j;
          }
        }
        if (p[0] > p[1]){
          cout << "Mike" << endl;
        } else {
          cout << "Joe" << endl;
        }
      }
    }
  }
}