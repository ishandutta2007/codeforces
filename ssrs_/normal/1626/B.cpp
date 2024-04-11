#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string x;
    cin >> x;
    int N = x.size();
    int p = -1;
    for (int j = N - 2; j >= 0; j--){
      if ((x[j] - '0') + (x[j + 1] - '0') >= 10){
        p = j;
        break;
      }
    }
    if (p != -1){
      int s = (x[p] - '0') + (x[p + 1] - '0');
      x[p] = '1';
      x[p + 1] = '0' + (s - 10);
      cout << x << endl;
    } else {
      x[0] += x[1] - '0';
      x.erase(x.begin() + 1);
      cout << x << endl;
    }
  }
}