#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> S(n + 1, 0);
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + a[i];
  }
  for (int i = 0; i < n; i++){
    cout << S[i + 1] / m - S[i] / m;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}