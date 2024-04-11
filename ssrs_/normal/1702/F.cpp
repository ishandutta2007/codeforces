#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    priority_queue<int> pq2;
    for (int j = 0; j < n; j++){
      int a;
      cin >> a;
      pq2.push(a);
    }
    priority_queue<int> pq1;
    for (int j = 0; j < n; j++){
      int b;
      cin >> b;
      pq1.push(b);
    }
    bool ok = true;
    while (!pq1.empty()){
      int x = pq1.top();
      int y = pq2.top();
      if (x == y){
        pq1.pop();
        pq2.pop();
      } else if (x > y){
        pq1.pop();
        pq1.push(x / 2);
      } else {
        if (y % 2 ==1){
          ok = false;
          break;
        } else {
          pq2.pop();
          pq2.push(y / 2);
        }
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}