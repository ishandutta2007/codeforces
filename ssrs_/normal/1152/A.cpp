#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; i++){
    cin >> b[i];
  }
  vector<int> c1(2, 0);
  for (int i = 0; i < n; i++){
    c1[a[i] % 2]++;
  }
  vector<int> c2(2, 0);
  for (int i = 0; i < m; i++){
    c2[b[i] % 2]++;
  }
  cout << min(c1[0], c2[1]) + min(c1[1], c2[0]) << endl;
}