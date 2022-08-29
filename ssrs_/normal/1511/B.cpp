#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> p(9);
    p[0] = 1;
    for (int i = 0; i < 8; i++){
      p[i + 1] = p[i] * 10;
    }
    int x = p[a - 1] + p[c - 1];
    int y = p[b - 1] + p[b - 1] + p[c - 1];
    cout << x << ' ' << y << endl;
  }
}