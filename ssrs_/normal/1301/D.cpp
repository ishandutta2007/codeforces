#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m,k;
  cin >> n >> m >> k;
  int R = 4 * n * m - 2 * n - 2 * m;
  if (k > R){
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    vector<pair<int,char>> M;
    if (m > 1){
      M.push_back(make_pair(m - 1, 'R'));
    }
    for (int i = 0; i < m - 1; i++){
      if (n > 1){
        M.push_back(make_pair(n - 1, 'D'));
        M.push_back(make_pair(n - 1, 'U'));
      }
      M.push_back(make_pair(1, 'L'));
    }
    for (int i = 0; i < n - 1; i++){
      M.push_back(make_pair(1, 'D'));
      if (m > 1){
        M.push_back(make_pair(m - 1, 'R'));
        M.push_back(make_pair(m - 1, 'L'));
      }
    }
    if (n > 1){
      M.push_back(make_pair(n - 1, 'U'));
    }
    int tdist = 0;
    int a;
    for (int i = 0; i < M.size(); i++){
      tdist += M[i].first;
      if (tdist >= k){
        a = i + 1;
        break;
      }
    }
    cout << a << endl;
    int rdist = 0;
    for (int i = 0; i < a - 1; i++){
      rdist += M[i].first;
      cout << M[i].first << ' ' << M[i].second << endl;
    }
    cout << k - rdist << ' ' << M[a - 1].second << endl;
  }
}