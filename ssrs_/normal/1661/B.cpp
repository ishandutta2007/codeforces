#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> d(32768, -1);
  d[0] = 0;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int x = Q.front();
    Q.pop();
    int p1 = (x + 32768 - 1) % 32768;
    if (d[p1] == -1){
      d[p1] = d[x] + 1;
      Q.push(p1);
    }
    if (x % 2 == 0){
      int p2 = x / 2;
      if (d[p2] == -1){
        d[p2] = d[x] + 1;
        Q.push(p2);
      }
      p2 += 32768 / 2;
      if (d[p2] == -1){
        d[p2] = d[x] + 1;
        Q.push(p2);
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << d[a[i]];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}