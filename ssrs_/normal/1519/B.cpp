#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, k;
    cin >> n >> m >> k;
    if (k == n * m - 1){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}