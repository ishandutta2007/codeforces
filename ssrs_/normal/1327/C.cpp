#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  cout << n * m + n + m - 2 << endl;
  for (int i = 0; i < n - 1; i++){
    cout << 'D';
  }
  for (int i = 0; i < m - 1; i++){
    cout << 'L';
  }
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n - 1; j++){
      cout << (i % 2 == 0 ? 'U' : 'D');
    }
    cout << 'R';
  }
}