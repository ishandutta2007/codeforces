#include <bits/stdc++.h>
using namespace std;
bool is_composite(int x){
  for (int i = 2; i * i <= x; i++){
    if (x % i == 0){
      return true;
    }
  }
  return false;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int x, d;
    cin >> x >> d;
    if (x / d % d != 0){
      cout << "NO" << endl;
    } else {
      int d2 = d;
      vector<pair<int, int>> P;
      for (int j = 2; j * j <= d2; j++){
        if (d2 % j == 0){
          int cnt = 0;
          while (d2 % j == 0){
            d2 /= j;
            cnt++;
          }
          P.push_back(make_pair(j, cnt));
        }
      }
      if (d2 > 1){
        P.push_back(make_pair(d2, 1));
      }
      if (P.size() == 1){
        if (P[0].second == 1){
          int p = P[0].first;
          while (x % p == 0){
            x /= p;
          }
          if (is_composite(x)){
            cout << "YES" << endl;
          } else {
            cout << "NO" << endl;
          }
        } else {
          int p = P[0].first;
          int e = P[0].second;
          int cnt = 0;
          while (x % p == 0){
            x /= p;
            cnt++;
          }
          if (e == 2){
            if (x == 1){
              if (cnt == 4 || cnt == 5 || cnt == 7){
                cout << "NO" << endl;
              } else {
                cout << "YES" << endl;
              }
            } else if (cnt == 4 && !is_composite(x)){
              cout << "NO" << endl;
            } else {
              cout << "YES" << endl;
            }
          } else {
            if (x == 1 && cnt == e * 2){
              cout << "NO" << endl;
            } else if (x == 1 && cnt == e * 2 + 1){
              cout << "NO" << endl;
            } else if (!is_composite(x) && cnt == e * 2){
              cout << "NO" << endl;
            } else {
              cout << "YES" << endl;
            }
          }
        }
      } else {
        int q = x / (d * d);
        if (is_composite(q)){
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      }
    }
  }
}