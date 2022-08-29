#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  deque<int> dq;
  for (int i = 0; i < n; i++){
    int a;
    cin >> a;
    dq.push_back(a);
  }
  int cnt = 0;
  while (!dq.empty()){
    if (dq.front() <= k){
      dq.pop_front();
      cnt++;
    } else {
      break;
    }
  }
  while (!dq.empty()){
    if (dq.back() <= k){
      dq.pop_back();
      cnt++;
    } else {
      break;
    }
  }
  cout << cnt << endl;
}