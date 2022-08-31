#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n;
    cin >> n;
    vector<pair<int, int>> P;
    for (int j = 0; j < n / 2; j++){
      P.push_back(make_pair(j * 2, j * 2 + 1));
    }
    if (n % 2 == 1){
      P.push_back(make_pair(n - 2, n - 1));
    }
    int m = P.size();
    vector<int> p(n);
    for (int j = 0; j < m; j++){
      int a = P[j].first;
      int b = P[j].second;
      cout << "? " << 1 << ' ' << a + 1 << ' ' << b + 1 << ' ' << n - 1 << endl;
      int res1;
      cin >> res1;
      cout << "? " << 2 << ' ' << a + 1 << ' ' << b + 1 << ' ' << 1 << endl;
      int res2;
      cin >> res2;
      if (res2 == 1){
        p[a] = 1;
        p[b] = res1;
      } else if (res1 == n){
        p[a] = res2;
        p[b] = n;
      } else if (3 <= res1 && res1 <= n - 2 && 3 <= res2 && res2 <= n - 2){
        cout << "? " << 1 << ' ' << a + 1 << ' ' << b + 1 << ' ' << res2 << endl;
        int res3;
        cin >> res3;
        if (res3 == res2){
          p[a] = res1;
          p[b] = res2;
        } else {
          p[a] = res2;
          p[b] = res1;
        }
      } else if (res1 == n - 1 && res2 == 2){
        cout << "? " << 1 << ' ' << a + 1 << ' ' << b + 1 << ' ' << 1 << endl;
        int res3;
        cin >> res3;
        cout << "? " << 2 << ' ' << a + 1 << ' ' << b + 1 << ' ' << n - 1 << endl;
        int res4;
        cin >> res4;
        if (res3 == 1 && res4 == n){
          p[a] = n;
          p[b] = 1;
        } else if (res3 == 2 && res4 == n){
          p[a] = n;
          p[b] = 2;
        } else if (res3 == 1 && res4 == n - 1){
          p[a] = n - 1;
          p[b] = 1;
        } else {
          cout << "? " << 1 << ' ' << a + 1 << ' ' << b + 1 << ' ' << 2 << endl;
          int res5;
          cin >> res5;
          if (res5 == 2){
            p[a] = n - 1;
            p[b] = 2;
          } else {
            p[a] = 2;
            p[b] = n - 1;
          }
        }
      } else if (res1 == 2 && res2 == 2){
        p[a] = 2;
        p[b] = 1;
      } else if (res1 == n - 1 && res2 == n - 1){
        p[a] = n;
        p[b] = n - 1;
      } else if (res1 < n - 1 && res2 == 2){
        cout << "? " << 1 << ' ' << a + 1 << ' ' << b + 1 << ' ' << 1 << endl;
        int res3;
        cin >> res3;
        if (res3 == 1){
          p[a] = res1;
          p[b] = 1;
        } else {
          cout << "? " << 1 << ' ' << a + 1 << ' ' << b + 1 << ' ' << 2 << endl;
          int res4;
          cin >> res4;
          if (res4 == 2){
            p[a] = res1;
            p[b] = 2;
          } else {
            p[a] = 2;
            p[b] = res1;
          }
        }
      } else if (res1 == n - 1 && res2 > 2){
        cout << "? " << 2 << ' ' << a + 1 << ' ' << b + 1 << ' ' << n - 1 << endl;
        int res3;
        cin >> res3;
        if (res3 == n){
          p[a] = n;
          p[b] = res2;
        } else {
          cout << "? " << 2 << ' ' << a + 1 << ' ' << b + 1 << ' ' << n - 2 << endl;
          int res4;
          cin >> res4;
          if (res4 == n - 1){
            p[a] = n - 1;
            p[b] = res2;
          } else {
            p[a] = res2;
            p[b] = n - 1;
          }
        }
      }
    }
    cout << "!";
    for (int j = 0; j < n; j++){
      cout << ' ' << p[j];
    }
    cout << endl;
  }
}