#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> p(n, 0);
  for (int i = 1; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<int> d(n, 0);
  int M = 0;
  for (int i = 1; i < n; i++){
    d[i] = d[p[i]] + 1;	
    M = max(M, d[i]);
  }
  vector<int> count(M + 1, 0);
  for (int i = 0; i < n; i++){
    count[d[i]]++;
  }
  int ans = 0;
  for (int i = 0; i <= M; i++){
    if (count[i] % 2 == 1){
      ans++;
    }
  }
  cout << ans << endl;
}