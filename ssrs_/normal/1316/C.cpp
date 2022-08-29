#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, p;
  cin >> n >> m >> p;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> b(m);
  for (int i = 0; i < m; i++){
    cin >> b[i];
  }
  int i = 0;
  while (a[i] % p == 0){
    i++;
  }
  int j = 0;
  while (b[j] % p == 0){
    j++;
  }
  int t = i + j;
  cout << t;
}