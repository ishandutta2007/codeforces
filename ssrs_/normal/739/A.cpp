#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> l(m), r(m);
  for (int i = 0; i < m; i++){
    cin >> l[i] >> r[i];
  }
  int L = n;
  for (int i = 0; i < m; i++){
    L = min(L, r[i] - l[i] + 1);
  }
  cout << L << endl;
  for (int i = 0; i < n; i++){
    cout << i % L;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}