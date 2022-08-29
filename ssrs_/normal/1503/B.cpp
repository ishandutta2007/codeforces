#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<pair<int, int>> p1, p2;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if ((i + j) % 2 == 0){
        p1.push_back(make_pair(i, j));
      } else {
        p2.push_back(make_pair(i, j));
      }
    }
  }
  for (int i = 0; i < n * n; i++){
    int a;
    cin >> a;
    if (!p1.empty() && !p2.empty()){
      if (a == 1){
        cout << 2 << ' ' << p2.back().first + 1 << ' ' << p2.back().second + 1 << endl;
        p2.pop_back();
      } else {
        cout << 1 << ' ' << p1.back().first + 1 << ' ' << p1.back().second + 1 << endl;
        p1.pop_back();
      }
    } else if (p1.empty()){
      if (a == 2){
        cout << 3 << ' ' << p2.back().first + 1 << ' ' << p2.back().second + 1 << endl;
        p2.pop_back();
      } else {
        cout << 2 << ' ' << p2.back().first + 1 << ' ' << p2.back().second + 1 << endl;
        p2.pop_back();
      }
    } else {
      if (a == 1){
        cout << 3 << ' ' << p1.back().first + 1 << ' ' << p1.back().second + 1 << endl;
        p1.pop_back();
      } else {
        cout << 1 << ' ' << p1.back().first + 1 << ' ' << p1.back().second + 1 << endl;
        p1.pop_back();
      }
    }
  }
}