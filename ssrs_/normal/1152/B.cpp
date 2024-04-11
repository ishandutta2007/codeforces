#include <bits/stdc++.h>
using namespace std;
int main(){
  int x;
  cin >> x;
  vector<int> op;
  int t = 0;
  while (x != (1 << 20) - 1){
    int n;
    for (int i = 19; i >= 0; i--){
      if ((x >> i & 1) == 0){
        n = i;
        break;
      }
    }
    x ^= (1 << (n + 1)) - 1;
    op.push_back(n + 1);
    t++;
    if (x != (1 << 20) - 1){
      x++;
      t++;
    }
  }
  cout << t << endl;
  int cnt = op.size();
  for (int i = 0; i < cnt; i++){
    cout << op[i];
    if (i < cnt - 1){
      cout << ' ';
    }
  }
  cout << endl;
}