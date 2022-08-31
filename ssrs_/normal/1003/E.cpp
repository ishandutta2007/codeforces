#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, d, k;
  cin >> n >> d >> k;
  if (k == 1){
    if (n == 1 && d == 0){
      cout << "YES" << endl;
    } else if (n == 2 && d == 1){
      cout << "YES" << endl;
      cout << 1 << ' ' << 2 << endl;
    } else {
      cout << "NO" << endl;
    }
  } else if (k == 2){
    if (d == n - 1){
      cout << "YES" << endl;
      for (int i = 0; i < n - 1; i++){
        cout << i + 1 << ' ' << i + 2 << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  } else if (n <= d){
    cout << "NO" << endl;
  } else {
    vector<pair<int, int>> E;
    for (int i = 0; i < d; i++){
      E.push_back(make_pair(i, i + 1));
    }
    queue<tuple<int, int, int>> Q;
    for (int i = 1; i < d; i++){
      Q.push(make_tuple(i, min(i, d - i), k - 2));
    }
    int c = d + 1;
    while (!Q.empty()){
      if (c == n){
        break;
      }
      int id = get<0>(Q.front());
      int dist = get<1>(Q.front());
      int deg = get<2>(Q.front());
      Q.pop();
      E.push_back(make_pair(id, c));
      if (dist > 1){
        Q.push(make_tuple(c, dist - 1, k - 1));
      }
      if (deg > 1){
        Q.push(make_tuple(id, dist, deg - 1));
      }
      c++;
    }
    if (c != n){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int i = 0; i < n - 1; i++){
        cout << E[i].first + 1 << ' ' << E[i].second + 1 << endl;
      }
    }
  }
}